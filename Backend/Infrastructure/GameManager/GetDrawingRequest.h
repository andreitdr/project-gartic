#pragma once

class GetDrawingRequest
{
public:
    GetDrawingRequest(int gameId);
    int GetGameId() const;
    
private:
    int m_gameId;
    
    
};
