#include "CheckWordRequest.h"

CheckWordRequest::CheckWordRequest(int gameId, int playerId, const std::string& word)
    : m_gameId{gameId}
    , m_playerId{playerId}
    , m_word{word}
{
}

int CheckWordRequest::GetGameId() const
{
    return m_gameId;
}

int CheckWordRequest::GetPlayerId() const
{
    return m_playerId;
}

std::string CheckWordRequest::GetWord() const
{
    return m_word;
}