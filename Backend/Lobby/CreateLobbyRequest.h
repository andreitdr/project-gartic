#pragma once

class CreateLobbyRequest
{
public:
    CreateLobbyRequest(int lobbyId,int userId);
    int GetLobbyId() const;
    int GetUserId() const;
private:
    int m_lobbyId;
    int m_userId;
};

inline CreateLobbyRequest::CreateLobbyRequest(int lobbyId, int userId):
m_lobbyId{lobbyId},
m_userId{userId}
{
}

inline int CreateLobbyRequest::GetLobbyId() const
{
    return m_lobbyId;
}

inline int CreateLobbyRequest::GetUserId() const
{
    return m_userId;
}

