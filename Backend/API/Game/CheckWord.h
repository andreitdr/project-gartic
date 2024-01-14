#pragma once

#include <crow.h>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/GameManagement/CheckWordContext.h"

inline WJSON CheckWord(const crow::json::rvalue& request)
{
    int gameId = request["gameId"].i();
    int playerId = request["playerId"].i();
    std::string word = request["word"].s();

    CheckWordRequest _request {gameId, playerId, word};
    CheckWordContext context {};

    CheckWordResponse response = context.HandleRequest(_request);
    WJSON jsonResponse = JsonConvertor::ConvertBaseResponse(response);

    return jsonResponse;
    
    
}