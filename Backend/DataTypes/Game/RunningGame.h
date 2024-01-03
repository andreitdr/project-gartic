#pragma once

#include <string>

struct RunningGame
{
    int m_gameId;
    std::string m_gameWords; // JSON string
    std::string m_userIds;   // JSON string
};
