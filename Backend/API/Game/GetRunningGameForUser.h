#pragma once
#include <crow/json.h>

#include "../../Contexts/Game/GameManagement/GetRunningGameForUserContext.h"
#include "../../Infrastructure/GameManager/GetRunningGameForUserRequest.h"
#include "../../Infrastructure/GameManager/GetRunningGameForUserResponse.h"
#include "../../Utils/JsonConvertor.h"


inline crow::json::wvalue GetRunningGameForUser(const crow::json::rvalue& request)
{
    int userId = request["userId"].i();

    GetRunningGameForUserRequest gameForUserRequest{userId};
    GetRunningGameForUserContext gameForUserContext{};

    GetRunningGameForUserResponse gameForUserResponse = gameForUserContext.HandleRequest(gameForUserRequest);

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(gameForUserResponse);
    JResponse["gameId"] = gameForUserResponse.GetGameId();

    return JResponse;

    
}
