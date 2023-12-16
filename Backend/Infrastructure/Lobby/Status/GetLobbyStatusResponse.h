#pragma once

import BaseResponse;
import Game;
#include <string>


class GetLobbyStatusResponse final : public BaseResponse
{
public:
    GetLobbyStatusResponse(const Lobby& lobby);
    GetLobbyStatusResponse(const std::string& message);
    Lobby GetLobby() const;

private:
    Lobby m_lobby;
};
