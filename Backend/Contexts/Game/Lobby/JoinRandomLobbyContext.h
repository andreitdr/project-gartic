#pragma once

#include "../../../Infrastructure/Lobby/Join/JoinRandomLobbyRequest.h"
#include "../../../Infrastructure/Lobby/Join/JoinRandomLobbyResponse.h"

#include "../../BaseContext.h"


class JoinRandomLobbyContext final : public BaseContext<JoinRandomLobbyRequest, JoinRandomLobbyResponse>
{
public:
    JoinRandomLobbyResponse HandleRequest(const JoinRandomLobbyRequest& request) override;

private:
    JoinRandomLobbyResponse ApplyChanges(const JoinRandomLobbyRequest& request) override;
    JoinRandomLobbyResponse ValidateData(const JoinRandomLobbyRequest& request) ;
    int GetRandomLobbyId() const;
};

