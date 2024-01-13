#pragma once

#include "../../../Infrastructure/Lobby/Leave/LeaveLobbyRequest.h"
#include "../../../Infrastructure/Lobby/Leave/LeaveLobbyResponse.h"
#include "../../BaseContext.h"

class LeaveLobbyContext final : public BaseContext<LeaveLobbyRequest, LeaveLobbyResponse>
{
public:
    LeaveLobbyResponse HandleRequest(const LeaveLobbyRequest& request) override;

private:
    LeaveLobbyResponse ValidateData(const LeaveLobbyRequest& request);
    LeaveLobbyResponse ApplyChanges(const LeaveLobbyRequest& request) override;
};

