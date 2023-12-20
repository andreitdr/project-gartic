#pragma once
#include <string>

import BaseResponse;
import Game;

class CreateLobbyResponse: public BaseResponse
{
public:
    CreateLobbyResponse(const Lobby& lobby);
    CreateLobbyResponse(const std::string& message);

    Lobby GetLobby() const;


private:
    Lobby m_lobby;
};

inline CreateLobbyResponse::CreateLobbyResponse(const Lobby& lobby) : m_lobby{ lobby }
{
    m_successState = true;
}

inline CreateLobbyResponse::CreateLobbyResponse(const std::string& message)
{
    m_successState = false;
    AppendMessage(message);
}

inline Lobby CreateLobbyResponse::GetLobby() const
{
    return m_lobby;
}
