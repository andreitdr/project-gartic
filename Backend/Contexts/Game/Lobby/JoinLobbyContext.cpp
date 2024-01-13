#include "JoinLobbyContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"
#include "../../../Utils/JsonConvertor.h"

#include <vector>
 JoinLobbyResponse JoinLobbyContext::HandleRequest(const JoinLobbyRequest& request)
{
    auto response = ValidateData(request);
    if (!response) return response;

    response = ApplyChanges(request);

    return response;
}

 JoinLobbyResponse JoinLobbyContext::ValidateData(const JoinLobbyRequest& request)
{
    int lobbyId = request.GetLobbyId();
    try
    {
        if (!SqlDatabase::GetInstance().Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId))) throw std::system_error(
            sqlite_orm::orm_error_code::not_found);

        return JoinLobbyResponse();
    }
    catch (std::system_error error)
    {
        if (error.code() == sqlite_orm::orm_error_code::not_found)
        {
            return JoinLobbyResponse(std::format("Lobby with id {} was not found", lobbyId));
        }

        return JoinLobbyResponse(error.what());
    }
}

 JoinLobbyResponse JoinLobbyContext::ApplyChanges(const JoinLobbyRequest& request)
{
    try
    {
        int lobbyId  = request.GetLobbyId();
        int playerId = request.GetUserId();


        auto currentLobby = SqlDatabase::GetInstance().Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

        std::vector<int> playersList = JsonConvertor::ConvertToVector<int>(currentLobby.m_userIds);
        playersList.emplace_back(playerId);
        currentLobby.m_userIds = JsonConvertor::ConvertFromVector(playersList).dump();

        SqlDatabase::GetInstance().Update(currentLobby);

        return JoinLobbyResponse();
    }
    catch (const std::system_error& error)
    {
        return JoinLobbyResponse(error.what());
    }
}
