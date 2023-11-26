export module Game;
#include <cstdint>
#include <string>
export struct Game
{
    uint32_t m_gameId;
    uint32_t m_winnerId;
    uint32_t m_gameDuration;
    
    /*
     *  The words are stored in the following format:
     *
     *  {
     *  round1: [ "word1", "word2", "word3" ],
     *  round2: [ "word1", "word2", "word3" ],
     *  ...
     *  }
     *
     *  The words are in the same order as they appeared in the game.
     */
    std::string m_gameWords;
};
