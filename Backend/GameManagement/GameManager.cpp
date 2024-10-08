﻿#include "GameManager.h"
#include "../SqlDatabase/SqlDatabase.h"
#include <format>
#include <thread>
#include <chrono>

#define GAME(gameId) GetGame(gameId)

bool GameManager::GameExists(int gameId) const
{
    if (gameId < 0)
        return false;

    bool exists = false;
    for (int i = 0; i < m_runningGames.size() && !exists; i++)
        if (m_runningGames[i].m_gameId == gameId)
            exists = true;

    return exists;
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
    game.m_playersWhoGuessed.clear();
    game.m_chatMessages.clear();
    game.m_playerPoints.clear();
    for(auto playerId : playerIds)
        game.m_playerPoints[playerId] = 0;

    game.m_gameId = m_runningGames.size();
    game.isRunning = true;

    m_runningGames.push_back(game);

    std::thread timerThread([this, gameId = game.m_gameId]()
        {
            RunningGame& game = GAME(gameId);
            while (game.isRunning)
            {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                {

                    if (game.m_timer <= 0 || game.m_playersWhoGuessed.size() == game.m_playerIds.size()-1)
                    {
                        FinishRound(gameId);
                        if (!ToNextRound(gameId))
                        {
                            std::cout << "\n\n\n\n\nSTOPPING GAME ID " << gameId << "\n\n\n\n";
                            EndGame(gameId);
                            break;
                        }
                    }
                    else
                    {
                        game.m_timer--;
                    }
                }
            }
        });
    timerThread.detach(); 

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
    const RunningGame& game = GAME(gameId);
    if (!game.m_gameWords.empty())
        return game.m_gameWords.front();

    throw "The queue is empty";
}

std::vector<int> GameManager::GetPlayerIds(int gameId) const
{
    return GAME(gameId).m_playerIds;
}

std::string GameManager::GetDrawing(int gameId) const
{
    return GAME(gameId).m_drawing;
}

void GameManager::FinishRound(int gameId)
{
    RunningGame& game = GAME(gameId);
    if(!game.m_playersWhoGuessed.empty())
    {
        int maxTime = 0;
        for (int time : game.m_guessTimes)
            maxTime += k_defaultTimerValue - time;
        maxTime += k_defaultTimerValue * (game.m_playerIds.size() - game.m_playersWhoGuessed.size());

        const float average = maxTime / game.m_playerIds.size();

        game.m_playerPoints[game.m_playerIds[game.m_indexPlayerDrawing]] += (k_defaultTimerValue - average) * 100 / k_defaultTimerValue;
    }
    else
		game.m_playerPoints[game.m_playerIds[game.m_indexPlayerDrawing]] -= 100;


    std::vector<int> playersFail;
    for(int playerId : game.m_playerIds)
    {
        if (playerId == game.m_playerIds[game.m_indexPlayerDrawing])
            continue;

        bool exists = false;
        for(int guessPlayerId : game.m_playersWhoGuessed)
            if(playerId == guessPlayerId)
            {
                exists = true;
                break;
            }

        if (!exists) 
            playersFail.emplace_back(playerId);
    }

    for (int pid : playersFail)
        game.m_playerPoints[pid] -= 50;

}

bool GameManager::ToNextRound(int gameId)
{
    GAME(gameId).m_indexPlayerDrawing ++;

    if(GAME(gameId).m_playerIds.size() <=  GAME(gameId).m_indexPlayerDrawing)
        GAME(gameId).m_indexPlayerDrawing = 0;

    if (GAME(gameId).m_gameWords.empty())
        return false;
    
    GAME(gameId).m_gameWords.pop();
    GAME(gameId).m_currentRound ++;

    if(GAME(gameId).m_currentRound + 1 > k_defaultNumberOfCycles * GAME(gameId).m_playerIds.size())
        return false;

    if(GAME(gameId).m_playerIds[GAME(gameId).m_indexPlayerDrawing] == -1)
    {
        return ToNextRound(gameId);
    }

    GAME(gameId).m_timer = k_defaultTimerValue;
    GAME(gameId).m_drawing = std::string();

    GAME(gameId).m_chatMessages.clear();
    GAME(gameId).m_playersWhoGuessed.clear();
    GAME(gameId).m_guessTimes.clear();
    
    return true;
}

bool GameManager::CheckWord(int gameId, const std::string& message) const
{
    return GetCurrentWord(gameId) == message;
}

void GameManager::AppendChatMessage(int gameId, int playerId, const std::string& message)
{
    
    if(playerId == -1)
        GAME(gameId).m_chatMessages.emplace_back(FormatMessage("GAME", message));
    else
    {
	    const auto player = SqlDatabase::GetInstance().Get<User>(playerId);
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

void GameManager::ManageCorrectAnswer(int gameId, int playerId)
{
    RunningGame& game = GAME(gameId);

    if(game.m_timer >= 30) // first 30 seconds
        game.m_playerPoints[playerId] += k_defaultMaxPoints;
    else
        game.m_playerPoints[playerId] += game.m_timer * 100 / 30;

    game.m_guessTimes.emplace_back(game.m_timer);
    game.m_playersWhoGuessed.emplace_back(playerId);
}

void GameManager::EndGame(int gameId)
{
    RunningGame& game = GetGame(gameId);

    for(int index = 0; index < game.m_playerIds.size(); index++)
    {
        PlayerFinishedGame fgame;
        fgame.m_gameId = game.m_gameId;
        fgame.m_userId = game.m_playerIds[index];
        fgame.m_pointsEarned = game.m_playerPoints[fgame.m_userId];
        fgame.m_index = -1;

        SqlDatabase::GetInstance().Insert<PlayerFinishedGame>(fgame);
    }

    GetGame(gameId).isRunning = false;

    DeleteGame(gameId);
    
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
    std::string _message = std::format("{}: {}", sender, message);
    return _message;
}

void GameManager::DeleteGame(int gameId)
{
    for (auto it = m_runningGames.begin(); it != m_runningGames.end(); ++it)
    {
        if (it->m_gameId == gameId)
        {
            m_runningGames.erase(it);
            break; 
        }
    }
}

