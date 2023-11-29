#include <crow.h>

#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "Contexts/Game/StartGameContext.h"

import StartGameRequest;
import StartGameResponse;

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
    // Create a running game in the database

    std::vector<int> playerList;
    for(auto& player : request["PlayerList"])
    {
        playerList.push_back(player.i());
    }

    StartGameRequest _request(playerList);
    StartGameResponse response = StartGameContext::StartGame(_request);

    crow::json::wvalue json;
    json = JsonConvertor::ConvertBaseResponse(response);
    json["GameID"] = response.GetGameID();
    json["Words"] = response.GetWords();
    json["PlayerList"] = playerList;
    
    return json;
    
}