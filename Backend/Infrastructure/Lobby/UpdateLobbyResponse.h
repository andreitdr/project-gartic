#pragma once

import BaseResponse;
#include <string>

class UpdateLobbyResponse final : public BaseResponse
{
public:
    UpdateLobbyResponse();
    UpdateLobbyResponse(const std::string& message);
};

UpdateLobbyResponse::UpdateLobbyResponse()
{
    m_successState=true;
}

UpdateLobbyResponse::UpdateLobbyResponse(const std::string& message)
{
    m_successState=false;
    AppendMessage(message);
}
