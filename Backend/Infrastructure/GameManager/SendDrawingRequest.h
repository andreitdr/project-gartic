#pragma once

#include <string>

class SendDrawingRequest
{
public:
    SendDrawingRequest(int gameId,const std::string& drawing);
    int GetGameId() const;
    std::string GetDrawing() const;

private:
    int m_gameId;
    std::string m_drawing;
};
