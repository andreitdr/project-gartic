#include "GetRunningGameStatusRequest.h"

GetRunningGameStatusRequest::GetRunningGameStatusRequest(int gameId)
    : m_gameId(gameId)
{
}

int GetRunningGameStatusRequest::GetGameId() const
{
    return m_gameId;
}