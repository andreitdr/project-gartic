#pragma once

class LeaveLobbyRequest
{
public:
    LeaveLobbyRequest(const int lobby_id, const int user_id);

    int GetLobbyId() const;
    int GetUserId() const;

private:
    int m_lobbyId;
    int m_userId;
};
