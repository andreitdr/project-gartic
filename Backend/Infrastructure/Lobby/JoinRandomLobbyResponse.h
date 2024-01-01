#pragma once

import BaseResponse;
#include <string>

class JoinRandomLobbyResponse final : public BaseResponse
{
public:
    JoinRandomLobbyResponse();
    JoinRandomLobbyResponse(const std::string& message);
};

JoinRandomLobbyResponse::JoinRandomLobbyResponse()
{
    m_successState = true;
}

JoinRandomLobbyResponse::JoinRandomLobbyResponse(const std::string& message)
{
    m_successState = false;
    AppendMessage(message);
}