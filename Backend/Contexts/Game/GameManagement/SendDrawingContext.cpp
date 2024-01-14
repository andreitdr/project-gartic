#include "SendDrawingContext.h"

#include <crow/app.h>

#include "../../../GameManagement/GameManager.h"

SendDrawingResponse SendDrawingContext::HandleRequest(const SendDrawingRequest& request)
{
    const int gameId = request.GetGameId();

    if(gameId<0)
        return SendDrawingResponse("Invalid game id");
    if(!GameManager::GetInstance().GameExists(gameId))
        return SendDrawingResponse("Game does not exist");
    return ApplyChanges(request);
}

SendDrawingResponse SendDrawingContext::ApplyChanges(const SendDrawingRequest& request)
{
    const int gameId = request.GetGameId();
    const std::string drawing = request.GetDrawing();

    GameManager::GetInstance().UpdateDrawing(gameId,drawing);

    return SendDrawingResponse();
}
