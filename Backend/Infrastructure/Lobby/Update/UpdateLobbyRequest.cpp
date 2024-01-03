#include "UpdateLobbyRequest.h"

UpdateLobbyRequest::UpdateLobbyRequest(const int lobbyId, const int lobbyType, bool isPrivate) : m_lobbyId{lobbyId},
    m_lobbyType{lobbyType}, m_isPrivate{isPrivate}
{
}

int UpdateLobbyRequest::GetLobbyId() const
{
    return m_lobbyId;
}

int UpdateLobbyRequest::GetLobbyType() const
{
    return m_lobbyType;
}

bool UpdateLobbyRequest::GetIsPrivate() const
{
    return m_isPrivate;
}
