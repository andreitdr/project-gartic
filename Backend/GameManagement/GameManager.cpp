#include "GameManager.h"
#include "../SqlDatabase/SqlDatabase.h"
#include <format>

#define GAME(gameId) m_runningGames[gameId]

int GameManager::GetTimer(int gameId) const
{
    return GAME(gameId).m_timer;
}

int GameManager::GetNowDrawingPlayer(int gameId) const
{
    return GAME(gameId).m_playerIds[GAME(gameId).m_indexPlayerDrawing];
}

int GameManager::GetCurrentRound(int gameId) const
{
    return GAME(gameId).m_currrentRound;
}

std::unordered_map<int, int> GameManager::GetPlayerLeaderboard(int gameId) const
{
    return GAME(gameId).m_playerPoints;
}

std::vector<std::string> GameManager::GetChat(int gameId) const
{
    return GAME(gameId).m_chatMessages;
}

std::string GameManager::GetCurrentWord(int gameId) const
{
    return GAME(gameId).m_gameWords.front();
}

bool GameManager::ToNextRound(int gameId)
{
    GAME(gameId).m_indexPlayerDrawing ++;

    if(GAME(gameId).m_playerIds.size() <=  GAME(gameId).m_indexPlayerDrawing)
        GAME(gameId).m_indexPlayerDrawing = 0;
    
    GAME(gameId).m_gameWords.pop();
    GAME(gameId).m_currrentRound ++;

    if(GAME(gameId).m_currrentRound > k_defaultNumberOfCycles * GAME(gameId).m_playerIds.size())
        return false;

    if(GAME(gameId).m_playerIds[GAME(gameId).m_indexPlayerDrawing] == -1)
    {
        return ToNextRound(gameId);
    }

    GAME(gameId).m_timer = k_defaultTimerValue;
    GAME(gameId).m_drawing = std::string();

    GAME(gameId).m_chatMessages.clear();
    
    return true;
}

bool GameManager::CheckWord(int gameId, const std::string& message) const
{
    return GetCurrentWord(gameId) == message;
}

void GameManager::AppendChatMessage(int gameId, int playerId, const std::string& message)
{
    
    if(playerId != -1)
        GAME(gameId).m_chatMessages.emplace_back(FormatMessage("GAME", message));
    else
    {
        auto player = SqlDatabase::GetInstance().Get<User>(playerId);
        GAME(gameId).m_chatMessages.emplace_back(FormatMessage(player.m_username, message));
    }
}

int GameManager::GetGameIdByPlayer(int playerId) const
{
    for(auto game : m_runningGames)
        for(auto element : game.m_playerIds)
            if(element == playerId)
                return game.m_gameId;

    return -1;
}

void GameManager::UpdatePoints(int gameId, int playerId, int pointsToAdd)
{
    GAME(gameId).m_playerPoints[playerId] += pointsToAdd;
}

std::string GameManager::FormatMessage(const std::string& sender, const std::string& message) const
{
    std::string _message = std::format("{} {}", sender, message);
    return _message;
}


