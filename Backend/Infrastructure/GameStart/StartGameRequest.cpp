#include "StartGameRequest.h"

StartGameRequest::StartGameRequest(int lobbyId) : m_lobbyId{lobbyId}
{
}

int StartGameRequest::GetLobbyId() const
{
    return m_lobbyId;
}
