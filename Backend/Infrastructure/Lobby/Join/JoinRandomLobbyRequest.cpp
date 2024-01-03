#include "JoinRandomLobbyRequest.h"

JoinRandomLobbyRequest::JoinRandomLobbyRequest(const int userId) : m_userId{userId}
{
}

int JoinRandomLobbyRequest::GetUserId() const
{
    return m_userId;
}
