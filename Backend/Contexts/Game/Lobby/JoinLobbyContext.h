#pragma once
#include "../../../Infrastructure/Lobby/Join/JoinLobbyRequest.h"
#include "../../../Infrastructure/Lobby/Join/JoinLobbyResponse.h"
#include "../../BaseContext.h"

class JoinLobbyContext final : public BaseContext<JoinLobbyRequest, JoinLobbyResponse>
{
public:
    JoinLobbyResponse HandleRequest(const JoinLobbyRequest& request) override;

private:
    JoinLobbyResponse ValidateData(const JoinLobbyRequest& request);
    JoinLobbyResponse ApplyChanges(const JoinLobbyRequest& request) override;
};
