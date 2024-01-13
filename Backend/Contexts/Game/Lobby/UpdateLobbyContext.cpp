#include "UpdateLobbyContext.h"
#include "../../../SqlDatabase/SqlDatabase.h"
#include "../../../Utils/JsonConvertor.h"

UpdateLobbyResponse UpdateLobbyContext::HandleRequest(const UpdateLobbyRequest& request)
{
    auto response = ValidateData(request);
    if (!response) return response;

    response = ApplyChanges(request);

    return response;
}

 UpdateLobbyResponse UpdateLobbyContext::ValidateData(const UpdateLobbyRequest& request)
{
    int lobbyId = request.GetLobbyId();

    try
    {
        if (!SqlDatabase::GetInstance().Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId))) throw std::system_error(
            sqlite_orm::orm_error_code::not_found);

        return UpdateLobbyResponse();
    }
    catch (std::system_error error)
    {
        if (error.code() == sqlite_orm::orm_error_code::not_found)
        {
            return UpdateLobbyResponse(std::format("Lobby with id {} was not found", lobbyId));
        }

        return UpdateLobbyResponse(error.what());
    }
}

 UpdateLobbyResponse UpdateLobbyContext::ApplyChanges(const UpdateLobbyRequest& request)
{
    int lobbyId        = request.GetLobbyId();
    int lobbyType      = request.GetLobbyType();
    int lobbyIsPrivate = request.GetIsPrivate();

    try
    {
        auto currentLobby = SqlDatabase::GetInstance().Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

        currentLobby.m_isPrivate = lobbyIsPrivate;
        currentLobby.m_lobbyType = lobbyType;

        SqlDatabase::GetInstance().Update(currentLobby);

        return UpdateLobbyResponse();
    }
    catch (const std::system_error& error)
    {
        return UpdateLobbyResponse(error.what());
    }
}
