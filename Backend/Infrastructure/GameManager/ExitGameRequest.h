#pragma once

class ExitGameRequest
{
public:
    ExitGameRequest(int gameId,int userId);
    int GetGameId() const;
    int GetUserId() const;

private:
    int m_gameId;
    int m_userId;
    
};
