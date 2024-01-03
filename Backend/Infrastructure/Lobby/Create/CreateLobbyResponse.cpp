#include "CreateLobbyResponse.h"

CreateLobbyResponse::CreateLobbyResponse(const Lobby& lobby) : m_lobby{lobby}
{
    m_successState = true;
}

CreateLobbyResponse::CreateLobbyResponse(const std::string& message)
{
    m_successState = false;
    AppendMessage(message);
}

Lobby CreateLobbyResponse::GetLobby() const
{
    return m_lobby;
}
