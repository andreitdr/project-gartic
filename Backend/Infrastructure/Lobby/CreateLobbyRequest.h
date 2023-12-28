#pragma once

class CreateLobbyRequest
{
public:
    CreateLobbyRequest(int userId, int lobbyType, bool isPrivate);
    int GetUserId() const;
    int GetLobbyType() const;
    bool GetIsPrivate() const;
private:
    int m_userId;
    int m_lobbyType;
    bool m_isPrivate;
};

inline CreateLobbyRequest::CreateLobbyRequest(int userId, int lobbyType, bool isPrivate):
m_userId{userId}, m_isPrivate{isPrivate}, m_lobbyType{lobbyType}
{
}

inline int CreateLobbyRequest::GetUserId() const
{
    return m_userId;
}

inline int CreateLobbyRequest::GetLobbyType() const
{
    return m_lobbyType;
}

inline bool CreateLobbyRequest::GetIsPrivate() const
{
    return m_isPrivate;
}

