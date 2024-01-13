#pragma once
#include <crow/json.h>

#include "../../Contexts/Game/GameManagement/ExitGameContext.h"
#include "../../Infrastructure/GameManager/ExitGameRequest.h"
#include "../../Utils/JsonConvertor.h"


inline crow::json::wvalue ExitGame(const crow::json::rvalue& request)
{
    int gameId = request["gameId"].i();
    int userId = request["userId"].i();

    ExitGameRequest exitGameRequest{gameId,userId};
    ExitGameContext exitGameContext{};

    ExitGameResponse exitGameResponse = exitGameContext.HandleRequest(exitGameRequest);

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(exitGameResponse);
    return JResponse;
}
