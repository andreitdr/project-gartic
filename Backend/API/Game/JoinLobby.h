#pragma once

#include <crow.h>
import JoinLobbyRequest;
import JoinLobbyResponse;

#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/JoinLobbyContext.h"



inline crow::json::wvalue JoinLobby(const crow::json::rvalue& request)
{
    const int lobbyId = request["lobbyId"].i();
    const int userId = request["userId"].i();

    const JoinLobbyRequest joinLobbyRequest(lobbyId, userId);
    JoinLobbyContext joinLobbyContext{};
    const JoinLobbyResponse joinLobbyResponse = joinLobbyContext.HandleRequest(joinLobbyRequest);

    WJSON json = JsonConvertor::ConvertBaseResponse(joinLobbyResponse);
    return json;
    
}