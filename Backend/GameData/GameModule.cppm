export module Game;
import <cstdint>;
import <string>;
import <vector>;

export struct FinishedGame
{
    int m_gameId;
    int m_winnerId;
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

export struct RunningGame
{
    int m_gameId;
    std::string m_gameWords;    // JSON string
    std::string m_userIds;      // JSON string
};

export struct Lobby
{
    int m_index;
    int m_lobbyId;
    int m_leaderId;

    int m_lobbyType;
    bool m_isPrivate;
    std::string m_userIds;     //JSON string 
};
