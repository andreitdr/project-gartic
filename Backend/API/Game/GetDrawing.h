#pragma once
#include <crow/json.h>

#include "../../Contexts/Game/GameManagement/GetDrawingContext.h"
#include "../../Infrastructure/GameManager/GetDrawingRequest.h"
#include "../../Utils/JsonConvertor.h"


inline crow::json::wvalue GetDrawing(const crow::json::rvalue& request)
{
    int gameId=request["gameId"].i();

    GetDrawingRequest getDrawingRequest{gameId};
    GetDrawingContext getDrawingContext{};

    GetDrawingResponse getDrawingResponse=getDrawingContext.HandleRequest(getDrawingRequest);

    WJSON JResult = JsonConvertor::ConvertBaseResponse(getDrawingResponse);
    JResult["drawing"]=getDrawingResponse.GetDrawing();

    return JResult;
}
