#pragma once

#include "../DataTypes/Game/RunningGame.h"

#include <string>

class GameManager
{
public:

    static GameManager& GetInstance()
    {
        static GameManager instance;
        return instance;
    }
    
    static constexpr int k_defaultTimerValue = 2;
    static constexpr int k_defaultNumberOfCycles=4;

    static constexpr int k_defaultMaxPoints = 100;

    bool GameExists(int gameId) const;

    RunningGame& GetGame(int gameId);
    const RunningGame& GetGame(int gameId) const;

    int CreateGame(const std::vector<int>& playerIds, const std::vector<std::string>& words);
    
    int GetTimer(int gameId) const;
    void SetTime(int gameId, int value);

    int GetNowDrawingPlayer(int gameId) const;
    int GetCurrentRound(int gameId)const;
    
    std::unordered_map<int, int> GetPlayerLeaderboard(int gameId) const;
    std::vector<std::string> GetChat(int gameId) const;
    std::string GetCurrentWord(int gameId) const;
    std::vector<int> GetPlayerIds(int gameId) const;
    std::string GetDrawing(int gameId) const;

    bool ToNextRound(int gameId);
    void FinishRound(int gameId);

    bool CheckWord(int gameId, const std::string& message) const;
    void AppendChatMessage(int gameId, int playerId, const std::string& message);
    
    int GetGameIdByPlayer(int playerId) const;

    void ManageCorrectAnswer(int gameId, int playerId);

	void EndGame(int gameId);

    void RemovePlayer(int gameId, int playerId);

    void UpdateDrawing(int gameId,const std::string& drawing);

    GameManager(const GameManager&);


    
    
private:
    std::vector<RunningGame> m_runningGames;
    std::string FormatMessage(const std::string& sender, const std::string& message) const;

    void DeleteGame(int gameId);
    GameManager() = default;
    
};
