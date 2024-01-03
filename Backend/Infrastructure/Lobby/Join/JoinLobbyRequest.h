#pragma once

class JoinLobbyRequest
{
public:
    JoinLobbyRequest(const int lobbyId, const int userId);

    int GetLobbyId() const;
    int GetUserId() const;

private:
    int m_lobbyId;
    int m_userId;
};
