#include "GetRunningGameForUserContext.h"

#include "../../../GameManagement/GameManager.h"
#include "../../../SqlDatabase/SqlDatabase.h"

GetRunningGameForUserResponse GetRunningGameForUserContext::HandleRequest(const GetRunningGameForUserRequest& request)
{
    const int id = request.GetUserId();
    if(id<0)
        return GetRunningGameForUserResponse("Invalid user id");
    if(!SqlDatabase::GetInstance().Exists<User>(WHERE(User::m_user_id,id)))
        return GetRunningGameForUserResponse("User does not exist");
    return ApplyChanges(request);
}

GetRunningGameForUserResponse GetRunningGameForUserContext::ApplyChanges(const GetRunningGameForUserRequest& request)
{
    const int id = request.GetUserId();
    const int game_id = GameManager::GetInstance().GetGameIdByPlayer(id);
    if(game_id ==-1)
        return GetRunningGameForUserResponse("User is not in a running game");
    return GetRunningGameForUserResponse(game_id);
}
