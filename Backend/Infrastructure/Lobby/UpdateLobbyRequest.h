#pragma once

class UpdateLobbyRequest
{
public:
    UpdateLobbyRequest(const int lobbyId, const int lobbyType, bool isPrivate);

    int GetLobbyId() const;
    int GetLobbyType() const;
    bool GetIsPrivate() const;

private:
    int m_lobbyId;
    int m_lobbyType;
    bool m_isPrivate;
};

inline UpdateLobbyRequest::UpdateLobbyRequest(const int lobbyId, const int lobbyType, bool isPrivate)
    : m_lobbyId{lobbyId}, m_lobbyType{lobbyType}, m_isPrivate{isPrivate}
{
}

inline int UpdateLobbyRequest::GetLobbyId() const
{
    return m_lobbyId;
}

inline int UpdateLobbyRequest::GetLobbyType() const
{
    return m_lobbyType;
}

inline bool UpdateLobbyRequest::GetIsPrivate() const
{
    return m_isPrivate;
}

