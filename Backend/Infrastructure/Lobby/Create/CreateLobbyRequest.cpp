#include "CreateLobbyRequest.h"

CreateLobbyRequest::CreateLobbyRequest(int userId, int lobbyType, bool isPrivate): m_userId{userId},
    m_lobbyType{lobbyType}, m_isPrivate{isPrivate}
{
}

int CreateLobbyRequest::GetUserId() const
{
    return m_userId;
}

int CreateLobbyRequest::GetLobbyType() const
{
    return m_lobbyType;
}

bool CreateLobbyRequest::GetIsPrivate() const
{
    return m_isPrivate;
}
