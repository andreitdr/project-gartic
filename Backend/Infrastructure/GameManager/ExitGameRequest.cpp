#include "ExitGameRequest.h"

ExitGameRequest::ExitGameRequest(int gameId, int userId): m_gameId{gameId},m_userId{userId}
{
    
}

int ExitGameRequest::GetGameId() const
{
    return m_gameId;
}

int ExitGameRequest::GetUserId() const
{
    return m_userId;
}
