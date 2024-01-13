#include "CheckWordContext.h"

#include "../../../GameManagement/GameManager.h"
#include "../../../SqlDatabase/SqlDatabase.h"

CheckWordResponse CheckWordContext::HandleRequest(const CheckWordRequest& request)
{
    auto response = ValidateData(request);
    if(!response)
        return response;

    return ApplyChanges(request);
}

CheckWordResponse CheckWordContext::ApplyChanges(const CheckWordRequest& request)
{
    const int playerId = request.GetPlayerId();
    const int gameId = request.GetGameId();
    const std::string word = request.GetWord();

    if(!GameManager::GetInstance().CheckWord(gameId, word))
    {
        GameManager::GetInstance().AppendChatMessage(gameId, playerId, word);
        return CheckWordResponse("Word is invalid", true);
    }

    const User user = SqlDatabase::GetInstance().Get<User>(playerId);

    GameManager::GetInstance().AppendChatMessage(gameId, -1, std::format("{} guessed the word !", user.m_username));
    return CheckWordResponse(true);
}

CheckWordResponse CheckWordContext::ValidateData(const CheckWordRequest& request)
{
    int gameId = request.GetGameId();
    int playerId = request.GetPlayerId();

    if (gameId < 0)
    {
        return CheckWordResponse( "Game id is invalid", false);
    }

    if (playerId < 0)
    {
        return CheckWordResponse( "Player id is invalid", false);
    }

    if(!SqlDatabase::GetInstance().Exists<User>(playerId))
    {
        return CheckWordResponse( "Player does not exist", false);
    }

    if(!GameManager::GetInstance().GameExists(gameId))
    {
        return CheckWordResponse( "Game does not exist", false);
    }

    return CheckWordResponse(true);
    
}
