#pragma once
#include <string>

#include "../../../Infrastructure/BaseResponse.h"
#include "../../../DataTypes/Game/Lobby.h"


class GetLobbyStatusResponse final : public BaseResponse
{
public:
    GetLobbyStatusResponse(const Lobby& lobby);
    GetLobbyStatusResponse(const std::string& message);
    Lobby GetLobby() const;

private:
    Lobby m_lobby;
};
