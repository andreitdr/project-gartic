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
