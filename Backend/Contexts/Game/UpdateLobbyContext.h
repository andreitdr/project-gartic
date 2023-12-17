#pragma once

#include "../../Infrastructure/Lobby/UpdateLobbyRequest.h"
#include "../../Infrastructure/Lobby/UpdateLobbyResponse.h"
#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "../BaseContext.h"

class UpdateLobbyContext final : public BaseContext<UpdateLobbyRequest, UpdateLobbyResponse>
{
public:
    UpdateLobbyResponse HandleRequest(const UpdateLobbyRequest& request);

private:
    UpdateLobbyResponse ValidateData(const UpdateLobbyRequest& request);
    UpdateLobbyResponse ApplyChanges(const UpdateLobbyRequest& request);
};

inline UpdateLobbyResponse UpdateLobbyContext::HandleRequest(const UpdateLobbyRequest& request)
{
    auto response = ValidateData(request);
    if (!response.GetSuccessState())
        return response;

    ApplyChanges(request);

    return response;
}

inline UpdateLobbyResponse UpdateLobbyContext::ValidateData(const UpdateLobbyRequest& request)
{
    int lobbyId = request.GetLobbyId();
    int newLeaderId = request.GetNewLeaderId();

    try
    {
        if (!SqlDatabase::Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId)))
            throw std::system_error(sqlite_orm::orm_error_code::not_found);

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

inline UpdateLobbyResponse UpdateLobbyContext::ApplyChanges(const UpdateLobbyRequest& request)
{
    int lobbyId = request.GetLobbyId();
    int newLeaderId = request.GetNewLeaderId();

    try
    {
        Lobby currentLobby = SqlDatabase::Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

        currentLobby.m_leaderId = newLeaderId;

        SqlDatabase::Update(currentLobby);

        return UpdateLobbyResponse();
    }
    catch (const std::system_error& error)
    {
        return UpdateLobbyResponse(error.what());
    }
}
