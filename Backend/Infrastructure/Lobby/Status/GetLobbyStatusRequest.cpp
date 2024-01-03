#include "GetLobbyStatusRequest.h"

GetLobbyStatusRequest::GetLobbyStatusRequest(int lobbyId) : m_lobbyId(lobbyId)
{
}

int GetLobbyStatusRequest::GetLobbyId() const
{
    return m_lobbyId;
}
