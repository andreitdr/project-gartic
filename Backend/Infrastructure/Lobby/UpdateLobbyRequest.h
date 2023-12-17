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

inline UpdateLobbyRequest::UpdateLobbyRequest(const int lobbyId, const int newLeaderId)
    : m_lobbyId(lobbyId), m_newLeaderId(newLeaderId)
{
}

inline int UpdateLobbyRequest::GetLobbyId() const
{
    return m_lobbyId;
}

inline int UpdateLobbyRequest::GetNewLeaderId() const
{
    return m_newLeaderId;
}