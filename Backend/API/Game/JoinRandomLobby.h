#pragma once

#include <crow.h>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/Lobby/JoinRandomLobbyContext.h"

inline crow::json::wvalue JoinRandomLobby(const crow::json::rvalue& request)
{
    const int userId = request["userId"].i();

    const JoinRandomLobbyRequest joinRandomLobbyRequest(userId);
    JoinRandomLobbyContext joinRandomLobbyContext{};
    const JoinRandomLobbyResponse joinRandomLobbyResponse = joinRandomLobbyContext.HandleRequest(joinRandomLobbyRequest);

    WJSON json = JsonConvertor::ConvertBaseResponse(joinRandomLobbyResponse);
    return json;
}