#pragma once
#include <format>
#include <crow.h>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/User/Info/UserMatchHistoryContext.h"

inline WJSON GetUserMatchHistoryData(const crow::json::rvalue& request)
{
    int userId = request["userId"].i();
    const UserMatchHistoryRequest historyRequest {userId};
    UserMatchHistoryContext context{};
    const UserMatchHistoryResponse response = context.HandleRequest(historyRequest);

    WJSON response_json = JsonConvertor::ConvertBaseResponse(response);
    
    for(auto game : response.GetFinishedGames())
    {
        std::string formattedGameName = std::format("{}", game.m_gameId);
        response_json["GameList"][formattedGameName] = game.m_pointsEarned;
    }
    
    response_json["TotalPoints"] = response.GetTotalPoints();
    response_json["AveragePoints"] = response.GetAveragePoints();

    return response_json;
}