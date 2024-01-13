#include "GetLobbyStatusResponse.h"

GetLobbyStatusResponse::GetLobbyStatusResponse(const Lobby& lobby) : BaseResponse(true), m_lobby{lobby}
{
    
}

GetLobbyStatusResponse::GetLobbyStatusResponse(const std::string& message) : BaseResponse(false)
{
    AppendMessage(message);
}

Lobby GetLobbyStatusResponse::GetLobby() const
{
    return m_lobby;
}
