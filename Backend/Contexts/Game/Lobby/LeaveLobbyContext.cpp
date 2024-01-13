#include "LeaveLobbyContext.h"
#include <vector>
#include "../../../SqlDatabase/SqlDatabase.h"
#include "../../../Utils/JsonConvertor.h"

LeaveLobbyResponse LeaveLobbyContext::HandleRequest(const LeaveLobbyRequest& request)
{
    auto response = ValidateData(request);
    if (!response.m_successState) return response;

    response = ApplyChanges(request);

    return response;
}

 LeaveLobbyResponse LeaveLobbyContext::ValidateData(const LeaveLobbyRequest& request)
{
    int lobbyId = request.GetLobbyId();
    try
    {
        if (!SqlDatabase::GetInstance().Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId))) throw std::system_error(
            sqlite_orm::orm_error_code::not_found);

        return LeaveLobbyResponse();
    }
    catch (std::system_error error)
    {
        if (error.code() == sqlite_orm::orm_error_code::not_found)
        {
            return LeaveLobbyResponse(std::format("Lobby with id {} was not found", lobbyId));
        }

        return LeaveLobbyResponse(error.what());
    }
}

 LeaveLobbyResponse LeaveLobbyContext::ApplyChanges(const LeaveLobbyRequest& request)
{
    int lobbyId  = request.GetLobbyId();
    int playerId = request.GetUserId();

    auto currentLobby = SqlDatabase::GetInstance().Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

    std::vector<int> playersList = JsonConvertor::ConvertToVector<int>(currentLobby.m_userIds);
    std::vector<int> newList;

    for (int user : playersList)
    {
        if (user != playerId) newList.emplace_back(user);
    }

    if (newList.empty())
    {
        SqlDatabase::GetInstance().Delete<Lobby>(currentLobby.m_index);
        auto response = LeaveLobbyResponse();
        response.AppendMessage("Lobby Deleted");

        return response;
    }

    if (playerId == currentLobby.m_leaderId) currentLobby.m_leaderId = newList[0];

    currentLobby.m_userIds = JsonConvertor::ConvertFromVector(newList).dump();

    SqlDatabase::GetInstance().Update(currentLobby);

    return LeaveLobbyResponse();
}
