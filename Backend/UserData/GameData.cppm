export module UserGameData;
#include <cstdint>

export struct UserGameData
{
    uint16_t m_gamesPlayed;
    uint16_t m_playerLevel;
    uint16_t m_playerCurrentExp;
};
