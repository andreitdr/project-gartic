#pragma once

#include <crow.h>
#include <format>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/GameManagement/GetRunningGameStatusContext.h"

inline WJSON GetRunningGameStatus(const crow::json::rvalue& request)
{
    const int gameId = request["gameId"].i();
    GetRunningGameStatusRequest _request {gameId };
    GetRunningGameStatusContext context {};
    const GetRunningGameStatusResponse response = context.HandleRequest(_request);

    WJSON jsonResponse = JsonConvertor::ConvertBaseResponse(response);
    jsonResponse["GameData"]["DrawingPlayerId"] = response.GetPlayerDrawingId();
    jsonResponse["GameData"]["CurrentRound"] = response.GetCurrentRound();
    jsonResponse["GameData"]["Timer"] = response.GetTimer();
    jsonResponse["GameData"]["CurrentWord"] = response.GetCurrentWord();
    jsonResponse["GameData"]["PlayerIds"] = response.GetPlayerIds();
    const auto playerPoints = response.GetPlayerPoints();
    for(auto const& [key, val] : playerPoints)
    {
        jsonResponse["GameData"]["PlayerPoints"][std::to_string(key)] = val;
    }

    return jsonResponse;
}