#pragma once

#include <string>

struct FinishedGame
{
    int m_gameId;
    int m_gameDuration;

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
