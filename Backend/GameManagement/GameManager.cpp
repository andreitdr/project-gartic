#include "GameManager.h"
#include "../SqlDatabase/SqlDatabase.h"
#include <format>
#include <thread>
#include <chrono>

#define GAME(gameId) GetGame(gameId)

bool GameManager::GameExists(int gameId) const
{
    if (gameId < 0)
        return false;

    if (m_runningGames.size() <= gameId)
        return false;

    return true;
}

RunningGame& GameManager::GetGame(int gameId)
{
    for(auto& game : m_runningGames)
		if(game.m_gameId == gameId)
			return game;

    throw std::exception("Game not found");
}

const RunningGame& GameManager::GetGame(int gameId) const
{
    for (const auto& game : m_runningGames)
        if (game.m_gameId == gameId)
            return game;

    throw std::exception("Game not found");
}

int GameManager::CreateGame(const std::vector<int>& playerIds, const std::vector<std::string>& words)
{
    RunningGame game = RunningGame();
    game.m_playerIds = playerIds;
    game.m_indexPlayerDrawing = 0;
    game.m_currentRound = 0;
    game.m_gameWords = std::queue<std::string>(words.begin(), words.end());
    game.m_timer = k_defaultTimerValue;
    game.m_drawing = std::string();
    game.m_chatMessages.clear();
    game.m_playerPoints.clear();
    for(auto playerId : playerIds)
        game.m_playerPoints[playerId] = 0;

    game.m_gameId = m_runningGames.size();
    m_runningGames.emplace_back(game);

    std::thread timerThread([this, gameId = game.m_gameId]()
        {
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                {
                    // Utilizează un mutex sau un alt mecanism de sincronizare aici dacă este necesar
                    if (GAME(gameId).m_timer <= 0)
                    {
                        if (!ToNextRound(gameId))
                        {
                            break;
                        }
                    }
                    else
                    {
                        GAME(gameId).m_timer--;
                    }
                }
            }
        });
    timerThread.detach(); // Detasează thread-ul

    return game.m_gameId;
    
}

int GameManager::GetTimer(int gameId) const
{
    return GAME(gameId).m_timer;
}

void GameManager::SetTime(int gameId, int value)
{
    GAME(gameId).m_timer = value;
}

int GameManager::GetNowDrawingPlayer(int gameId) const
{
    const RunningGame& game = GAME(gameId);
    return game.m_playerIds[game.m_indexPlayerDrawing];
}

int GameManager::GetCurrentRound(int gameId) const
{
    return GAME(gameId).m_currentRound;
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

std::vector<int> GameManager::GetPlayerIds(int gameId) const
{
    return GAME(gameId).m_playerIds;
}

std::string GameManager::GetDrawing(int gameId) const
{
    return GAME(gameId).m_drawing;
}

bool GameManager::ToNextRound(int gameId)
{
    GAME(gameId).m_indexPlayerDrawing ++;

    if(GAME(gameId).m_playerIds.size() <=  GAME(gameId).m_indexPlayerDrawing)
        GAME(gameId).m_indexPlayerDrawing = 0;
    
    GAME(gameId).m_gameWords.pop();
    GAME(gameId).m_currentRound ++;

    if(GAME(gameId).m_currentRound > k_defaultNumberOfCycles * GAME(gameId).m_playerIds.size())
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

void GameManager::RemovePlayer(int gameId, int playerId)
{
    for(int i=0; i < GAME(gameId).m_playerIds.size();i++)
        if(GAME(gameId).m_playerIds[i]==playerId)
            GAME(gameId).m_playerIds[i]=-1;
}

void GameManager::UpdateDrawing(int gameId, const std::string& drawing)
{
    GAME(gameId).m_drawing=drawing;
}

GameManager::GameManager(const GameManager& otherGame)
{
    // Copy constructor
    m_runningGames = otherGame.m_runningGames;

}

std::string GameManager::FormatMessage(const std::string& sender, const std::string& message) const
{
    std::string _message = std::format("{} {}", sender, message);
    return _message;
}

