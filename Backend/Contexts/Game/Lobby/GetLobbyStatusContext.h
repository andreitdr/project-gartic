#pragma once

#include "../../../Contexts/BaseContext.h"
#include "../../../Infrastructure/Lobby/Status/GetLobbyStatusRequest.h"
#include "../../../Infrastructure/Lobby/Status/GetLobbyStatusResponse.h"

class GetLobbyStatusContext final : public BaseContext<GetLobbyStatusRequest, GetLobbyStatusResponse>
{
public:
    GetLobbyStatusResponse HandleRequest(const GetLobbyStatusRequest& request) override;

private:
    GetLobbyStatusResponse ApplyChanges(const GetLobbyStatusRequest& request) override;
    static bool ValidateLobbyExists(int lobbyId);
};
