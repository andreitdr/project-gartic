#pragma once

#include <crow.h>
#include "../../Infrastructure/Lobby/Update/UpdateLobbyRequest.h"
#include "../../Infrastructure/Lobby/Update/UpdateLobbyResponse.h"
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/Lobby/UpdateLobbyContext.h"

inline crow::json::wvalue UpdateLobby(const crow::json::rvalue& request)
{
    const int lobbyId         = request["lobbyId"].i();
    const int lobbyType       = request["lobbyType"].i();
    const bool lobbyisPrivate = request["IsPrivate"].b();

    const UpdateLobbyRequest updateLobbyRequest(lobbyId, lobbyType, lobbyisPrivate);
    UpdateLobbyContext updateLobbyContext{};
    const UpdateLobbyResponse updateLobbyResponse = updateLobbyContext.HandleRequest(updateLobbyRequest);

    WJSON json = JsonConvertor::ConvertBaseResponse(updateLobbyResponse);
    return json;
}
