#pragma once

class JoinRandomLobbyRequest
{
public:
    JoinRandomLobbyRequest(const int userId);

    int GetUserId() const;

private:
    int m_userId;
};
