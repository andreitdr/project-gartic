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

inline UpdateLobbyResponse::UpdateLobbyResponse() : m_successState(true) {}

inline UpdateLobbyResponse::UpdateLobbyResponse(const std::string& message)
    : m_successState(false), m_message(message)
{
}

inline bool UpdateLobbyResponse::GetSuccessState() const
{
    return m_successState;
}

inline const std::string& UpdateLobbyResponse::GetMessage() const
{
    return m_message;
}
