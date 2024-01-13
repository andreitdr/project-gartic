#pragma once
#include <string>
class CheckWordRequest
{
public:
    CheckWordRequest(int gameId, int playerId, const std::string& word);

    int GetGameId() const;
    int GetPlayerId() const;
    std::string GetWord() const;
private:
    int m_gameId;
    int m_playerId;
    std::string m_word;
};
