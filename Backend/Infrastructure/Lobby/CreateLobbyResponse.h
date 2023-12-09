#pragma once
import BaseResponse;

#include <vector>
#include <string>

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
