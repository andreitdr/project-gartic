#pragma once

import BaseResponse;
#include <string>

class UpdateLobbyResponse : public BaseResponse
{
public:
    UpdateLobbyResponse();
    UpdateLobbyResponse(const std::string& message);

    bool GetSuccessState() const;
    const std::string& GetMessage() const;

private:
    bool m_successState;
    std::string m_message;
};
