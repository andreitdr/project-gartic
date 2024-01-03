#pragma once
#include <crow.h>

#include "../../Utils/JsonConvertor.h"
#include "Contexts/Game/StartGameContext.h"

#include "../../Infrastructure/GameStart/StartGameRequest.h"
#include "../../Infrastructure/GameStart/StartGameResponse.h"

/*
 * Json input:
 * PlayerList: [int] -> List of user ids
 *
 *
 *  Returns:
 *  Json Output:
 *  GameID: int,
 *  SuccessState: bool,
 *  Words: [string]
 */

inline crow::json::wvalue StartGame(const crow::json::rvalue& request)
{
    std::vector<int> playerList;
    for (auto& player : request["PlayerList"])
    {
        playerList.push_back(player.i());
    }

    auto _request = StartGameRequest(playerList);
    auto context  = StartGameContext();

    StartGameResponse response = context.HandleRequest(_request);

    crow::json::wvalue json;
    json               = JsonConvertor::ConvertBaseResponse(response);
    json["GameID"]     = response.GetGameID();
    json["Words"]      = response.GetWords();
    json["PlayerList"] = playerList;

    return json;
}
