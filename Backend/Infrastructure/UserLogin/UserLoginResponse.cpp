#include "UserLoginResponse.h"

UserLoginResponse::UserLoginResponse(const std::string& message, bool state)
{
    AppendMessage(message);
    m_successState = state;
}

UserLoginResponse::UserLoginResponse(bool state) : BaseResponse()
{
    m_successState = state;
}
