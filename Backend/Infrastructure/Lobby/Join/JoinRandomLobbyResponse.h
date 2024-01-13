#pragma once

#include <string>

#include "../../BaseResponse.h"

class JoinRandomLobbyResponse final : public BaseResponse
{
public:
    JoinRandomLobbyResponse(int lobbyId);
    JoinRandomLobbyResponse(const std::string& message);
    JoinRandomLobbyResponse(bool state);

    int GetLobbyId() const;

private:
    int m_lobbyId;
};

