#pragma once
#include <crow.h>

#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/StartGameContext.h"

#include "../../Infrastructure/GameStart/StartGameRequest.h"
#include "../../Infrastructure/GameStart/StartGameResponse.h"

/*
 * Json input:
 * Lobby -> Lobby Data (Lobby struct):
 *       PlayerList -> List of player IDs (int)
 *       LobbyId -> Lobby ID (int)
 *       LobbyLeader -> Lobby Leader ID (int)
 *       LobbyType -> Lobby Type (int)
 *       LobbyIsPrivate -> Lobby Privacy (bool)
 *
 *
 *
 *  Returns:
 *      - GameID (int)
 *      - started (bool)
 */

inline crow::json::wvalue StartGame(const crow::json::rvalue& request)
{
    int lobbyId = request["Lobby"]["lobbyId"].i();

    StartGameRequest startGameRequest{lobbyId};
    StartGameContext startGameContext{};

    StartGameResponse startGameResponse = startGameContext.HandleRequest(startGameRequest);

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(startGameResponse);
    JResponse["gameId"] = startGameResponse.GetGameID();

    return JResponse;
}
