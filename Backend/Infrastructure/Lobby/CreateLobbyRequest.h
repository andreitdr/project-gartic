#pragma once

class CreateLobbyRequest
{
public:
    CreateLobbyRequest(int userId);
    int GetUserId() const;
private:
    int m_userId;
};

inline CreateLobbyRequest::CreateLobbyRequest(int userId):
m_userId{userId}
{
}

inline int CreateLobbyRequest::GetUserId() const
{
    return m_userId;
}

