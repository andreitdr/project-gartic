#pragma once
class GetLobbyStatusRequest
{
public:
    GetLobbyStatusRequest(int lobbyId);
    int GetLobbyId() const;

private:
    int m_lobbyId;
};
