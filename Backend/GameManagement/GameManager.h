﻿#pragma once

#include "../DataTypes/Game/RunningGame.h"

class GameManager
{
public:

    static GameManager& GetInstance()
    {
        static GameManager instance;
        return instance;
    }
    
    const int k_defaultTimerValue = 60;
    const int k_defaultNumberOfCycles = 4;
    
    int GetTimer(int gameId) const;
    int GetNowDrawingPlayer(int gameId) const;
    int GetCurrentRound(int gameId)const;
    
    std::unordered_map<int, int> GetPlayerLeaderboard(int gameId) const;
    std::vector<std::string> GetChat(int gameId) const;
    std::string GetCurrentWord(int gameId) const;

    bool ToNextRound(int gameId);

    bool CheckWord(int gameId, const std::string& message) const;
    void AppendChatMessage(int gameId, int playerId, const std::string& message);
    
    int GetGameIdByPlayer(int playerId) const;

    void UpdatePoints(int gameId, int playerId, int pointsToAdd);

    void operator=(const GameManager&) = delete;
    GameManager(const GameManager&) = delete;
    
    
private:
    std::vector<RunningGame> m_runningGames;
    std::string FormatMessage(const std::string& sender, const std::string& message) const;

    GameManager() = default;
    
};
