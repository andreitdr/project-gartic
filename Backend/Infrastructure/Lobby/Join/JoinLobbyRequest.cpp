#include "JoinLobbyRequest.h"

JoinLobbyRequest::JoinLobbyRequest(const int lobbyId, const int userId) : m_lobbyId{lobbyId}, m_userId{userId}
{
}

int JoinLobbyRequest::GetLobbyId() const
{
    return m_lobbyId;
}

int JoinLobbyRequest::GetUserId() const
{
    return m_userId;
}
