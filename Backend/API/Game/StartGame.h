#include <crow.h>

#include "../../SqlDatabase/SqlDatabase.h"

import StartGameContext;
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

    StartGameRequest request(playerList);
    StartGameResponse response = StartGameContext::StartGame(request);

    crow::json::wvalue json;
        
    return json;
    
}