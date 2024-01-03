#pragma once
#include <string>

#include "../../../Infrastructure/BaseResponse.h"
#include "../../../DataTypes/Game/Lobby.h"

class CreateLobbyResponse : public BaseResponse
{
public:
    CreateLobbyResponse(const Lobby& lobby);
    CreateLobbyResponse(const std::string& message);

    Lobby GetLobby() const;

private:
    Lobby m_lobby;
};
