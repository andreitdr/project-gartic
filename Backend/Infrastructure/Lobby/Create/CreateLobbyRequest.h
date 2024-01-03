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
