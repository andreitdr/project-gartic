#pragma once
#include <crow/json.h>

#include "../../Contexts/Game/GameManagement/SendDrawingContext.h"
#include "../../Infrastructure/GameManager/SendDrawingRequest.h"
#include "../../Utils/JsonConvertor.h"


inline crow::json::wvalue SendDrawing(const crow::json::rvalue& request)
{
    int gameId = request["gameId"].i();
    std::string drawing = request["drawing"].s();

    SendDrawingRequest sendDrawingRequest{gameId,drawing};
    SendDrawingContext sendDrawingContext{};

    SendDrawingResponse sendDrawingResponse=sendDrawingContext.HandleRequest(sendDrawingRequest);

    WJSON JResult = JsonConvertor::ConvertBaseResponse(sendDrawingResponse);

    return JResult;
    
}
