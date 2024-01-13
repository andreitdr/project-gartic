#pragma once

class GetChatMessagesRequest
{
public:
    GetChatMessagesRequest(int gameId);
    int GetGameId() const;
private:
    int m_gameId;
    
};
