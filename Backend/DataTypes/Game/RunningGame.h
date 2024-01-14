#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

class RunningGame
{
public:
    int m_gameId;
    int m_indexPlayerDrawing;
    int m_currentRound;

    int m_timer;
    std::string m_drawing;

    
    std::unordered_map<int, int> m_playerPoints;
    std::vector<int> m_guessTimes;
    std::vector<int> m_playersWhoGuessed;
    std::vector<int> m_playerIds;
    
    
    std::vector<std::string> m_chatMessages;
    std::queue<std::string> m_gameWords;

    RunningGame(int gameId, const std::vector<int>& playerIds, const std::vector<std::string>& words);
    RunningGame(const RunningGame& other);
    RunningGame(RunningGame&& other) noexcept;
    RunningGame() = default;
    RunningGame& operator=(const RunningGame& other);
};
