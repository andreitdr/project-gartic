#include "UserMatchHistoryContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"
UserMatchHistoryResponse UserMatchHistoryContext::HandleRequest(const UserMatchHistoryRequest& request)
{
    auto response = ValidateData(request);
    if(!response)
        return response;

    response = ApplyChanges(request);
    return response;
}

UserMatchHistoryResponse UserMatchHistoryContext::ApplyChanges(const UserMatchHistoryRequest& request)
{
    const int userId = request.GetUserId();
    const std::vector<PlayerFinishedGame> finished_games = SqlDatabase::GetInstance().GetAll<PlayerFinishedGame>(WHERE(PlayerFinishedGame::m_userId, userId));

    return UserMatchHistoryResponse(finished_games);
}

UserMatchHistoryResponse UserMatchHistoryContext::ValidateData(const UserMatchHistoryRequest& request)
{
    const int userId = request.GetUserId();
    if(!SqlDatabase::GetInstance().Exists<User>(userId))
        return UserMatchHistoryResponse("User does not exist");


    return UserMatchHistoryResponse();
}
