#include "ExitGameContext.h"

#include "../../../DataTypes/Game/RunningGame.h"
#include "../../../GameManagement/GameManager.h"
#include "../../../SqlDatabase/SqlDatabase.h"


ExitGameResponse ExitGameContext::HandleRequest(const ExitGameRequest& request)
{
    const int gameId = request.GetGameId();
    const int userId = request.GetUserId();

    if(userId<0)
        return ExitGameResponse("Invalid user id");
    if(!SqlDatabase::GetInstance().Exists<User>(WHERE(User::m_user_id,userId)))
        return ExitGameResponse("User does not exist");
    
    if(gameId<0)
        return ExitGameResponse("Invalid game id");
    if(!GameManager::GetInstance().GameExists(gameId))
        return ExitGameResponse("Game does not exist");

    
    return ApplyChanges(request);
}

ExitGameResponse ExitGameContext::ApplyChanges(const ExitGameRequest& request)
{
    int gameId = request.GetGameId();
    int userId = request.GetUserId();

    GameManager::GetInstance().RemovePlayer(gameId,userId);
    return ExitGameResponse();
}
