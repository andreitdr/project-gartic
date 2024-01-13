#include "SendDrawingRequest.h"

SendDrawingRequest::SendDrawingRequest(int gameId, const std::string& drawing): m_gameId{gameId}, m_drawing(drawing)
{
}

int SendDrawingRequest::GetGameId() const
{
    return m_gameId;
}

std::string SendDrawingRequest::GetDrawing() const
{
    return m_drawing;
}
