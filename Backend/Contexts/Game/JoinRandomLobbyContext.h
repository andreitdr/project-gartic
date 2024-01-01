#pragma once

#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "../BaseContext.h"
#include "../../Infrastructure/Lobby/JoinRandomLobbyRequest.h"
#include "../../Infrastructure/Lobby/JoinRandomLobbyResponse.h"

class JoinRandomLobbyContext final : public BaseContext<JoinRandomLobbyRequest, JoinRandomLobbyResponse>
{
public:
    JoinRandomLobbyResponse HandleRequest(const JoinRandomLobbyRequest& request) override;

private:
    JoinRandomLobbyResponse ApplyChanges(const JoinRandomLobbyRequest& request) override;
};
