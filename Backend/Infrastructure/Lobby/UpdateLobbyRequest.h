#pragma once

class UpdateLobbyRequest
{
public:
    UpdateLobbyRequest(const int lobbyId, const int newLeaderId);

    int GetLobbyId() const;
    int GetNewLeaderId() const;

private:
    int m_lobbyId;
    int m_newLeaderId;
};
