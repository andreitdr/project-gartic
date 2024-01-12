#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

struct RunningGame
{
    int m_gameId;
    int m_indexPlayerDrawing;
    int m_currrentRound;

    int m_timer;
    std::string m_drawing;

    
    std::unordered_map<int, int> m_playerPoints;
    std::vector<int> m_guessTimes;
    std::vector<int> m_playerIds;
    
    
    std::vector<std::string> m_chatMessages;
    std::queue<std::string> m_gameWords;
};
