#pragma once

class JoinRandomLobbyRequest
{
public:
    JoinRandomLobbyRequest(const int userId);

    int GetUserId() const;

private:
    int m_userId;
};

JoinRandomLobbyRequest::JoinRandomLobbyRequest(const int userId) : m_userId{ userId }
{
}

int JoinRandomLobbyRequest::GetUserId() const
{
    return m_userId;
}
