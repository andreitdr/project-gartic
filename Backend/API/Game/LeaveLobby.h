#pragma once

#include <crow.h>

#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/Lobby/LeaveLobbyContext.h"

inline crow::json::wvalue LeaveLobby(const crow::json::rvalue& request)
{
    const int lobbyId = request["lobbyId"].i();
    const int userId  = request["userId"].i();

    const LeaveLobbyRequest leaveLobbyRequest(lobbyId, userId);
    LeaveLobbyContext leaveLobbyContext{};
    const LeaveLobbyResponse leaveLobbyResponse = leaveLobbyContext.HandleRequest(leaveLobbyRequest);

    WJSON json = JsonConvertor::ConvertBaseResponse(leaveLobbyResponse);
    return json;
}
