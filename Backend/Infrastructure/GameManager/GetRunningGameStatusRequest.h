#pragma once

class GetRunningGameStatusRequest
{
public:
    GetRunningGameStatusRequest(int gameId);
    int GetGameId() const;
    
private:
    int m_gameId;
};
