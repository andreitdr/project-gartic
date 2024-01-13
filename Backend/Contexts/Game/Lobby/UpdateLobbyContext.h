#pragma once

#include "../../../Infrastructure/Lobby/Update/UpdateLobbyRequest.h"
#include "../../../Infrastructure/Lobby/Update/UpdateLobbyResponse.h"

#include "../../BaseContext.h"

class UpdateLobbyContext final : public BaseContext<UpdateLobbyRequest, UpdateLobbyResponse>
{
public:
    UpdateLobbyResponse HandleRequest(const UpdateLobbyRequest& request) override;

private:
    UpdateLobbyResponse ValidateData(const UpdateLobbyRequest& request);
    UpdateLobbyResponse ApplyChanges(const UpdateLobbyRequest& request) override;
};

