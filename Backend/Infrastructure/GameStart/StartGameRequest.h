#pragma once

class StartGameRequest
{
public:
    StartGameRequest(int lobbyId);
    int GetLobbyId() const;

private:
    int m_lobbyId;
};
