#include "GetDrawingContext.h"

#include "../../../GameManagement/GameManager.h"

GetDrawingResponse GetDrawingContext::HandleRequest(const GetDrawingRequest& request)
{
    const int gameId = request.GetGameId();

    if(gameId<0)
        return GetDrawingResponse("Invalid game id");
    if(!GameManager::GetInstance().GameExists(gameId))
        return GetDrawingResponse("Game does not exist");

    ApplyChanges(request);
}

GetDrawingResponse GetDrawingContext::ApplyChanges(const GetDrawingRequest& request)
{
    const int gameId = request.GetGameId();

    const std::string drawing = GameManager::GetInstance().GetDrawing(gameId);

    return GetDrawingResponse(drawing,true);
}
