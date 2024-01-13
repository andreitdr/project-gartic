#include "GetChatMessagesRequest.h"

GetChatMessagesRequest::GetChatMessagesRequest(int gameId)
    : m_gameId{gameId}
{
}

int GetChatMessagesRequest::GetGameId() const
{
    return m_gameId;
}