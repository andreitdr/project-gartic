#include "GetRunningGameStatusContext.h"
#include "../../../GameManagement/GameManager.h"

GetRunningGameStatusResponse GetRunningGameStatusContext::HandleRequest(const GetRunningGameStatusRequest& request)
{
    auto response = ValidateData(request);
    if(!response)
        return response;

    return ApplyChanges(request);
}

GetRunningGameStatusResponse GetRunningGameStatusContext::ApplyChanges(const GetRunningGameStatusRequest& request)
{
    const int game_id = request.GetGameId();
    const int drawingPlayerId = GameManager::GetInstance().GetNowDrawingPlayer(game_id);
    const int currentRound = GameManager::GetInstance().GetCurrentRound(game_id);
    const int timer = GameManager::GetInstance().GetTimer(game_id);

    const std::string currentWord = GameManager::GetInstance().GetCurrentWord(game_id);
    const std::vector<int> playerIds = GameManager::GetInstance().GetPlayerIds(game_id);
    const std::unordered_map<int, int> playerPoints = GameManager::GetInstance().GetPlayerLeaderboard(game_id);

    return GetRunningGameStatusResponse(drawingPlayerId, currentRound, timer, currentWord, playerIds, playerPoints);


}

GetRunningGameStatusResponse GetRunningGameStatusContext::ValidateData(const GetRunningGameStatusRequest& request)
{
    const int game_id = request.GetGameId();
    if(game_id < 0)
    {
        return GetRunningGameStatusResponse("Game id must be positive", false);
    }

    if(!GameManager::GetInstance().GameExists(game_id))
        return GetRunningGameStatusResponse("Game does not exist", false);

    return GetRunningGameStatusResponse(true);
}

