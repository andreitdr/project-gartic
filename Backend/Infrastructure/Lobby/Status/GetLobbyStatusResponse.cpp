#include "GetLobbyStatusResponse.h"

GetLobbyStatusResponse::GetLobbyStatusResponse(const Lobby& lobby) : BaseResponse(), m_lobby(lobby)
{
    m_successState = true;
}

GetLobbyStatusResponse::GetLobbyStatusResponse(const std::string& message) : BaseResponse()
{
    m_successState = false;
    AppendMessage(message);
}

Lobby GetLobbyStatusResponse::GetLobby() const
{
    return m_lobby;
}
