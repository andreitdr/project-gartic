#include "GetDrawingRequest.h"

GetDrawingRequest::GetDrawingRequest(int gameId):m_gameId{gameId}
{
}

int GetDrawingRequest::GetGameId() const
{
    return m_gameId;
}
