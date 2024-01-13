#pragma once

#include "../../../Infrastructure/Lobby/Create/CreateLobbyRequest.h"
#include "../../../Infrastructure/Lobby/Create/CreateLobbyResponse.h"
#include "../../BaseContext.h"


class CreateLobbyContext final : public BaseContext<CreateLobbyRequest, CreateLobbyResponse>
{
public:
    CreateLobbyResponse HandleRequest(const CreateLobbyRequest& request) override;

private:
    enum LobbyConstraints
    {
        // Lobby Min value for ID
        lobby_id_min = 100000,

        // Lobby Max value for ID
        lobby_id_max = 9999999
    };


    CreateLobbyResponse ApplyChanges(const CreateLobbyRequest& request) override;

    bool LobbyExists(int lobbyId);
    uint32_t GenerateLobbyId();
};

