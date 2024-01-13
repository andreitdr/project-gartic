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

UserLoginResponse::UserLoginResponse(const User& user) : BaseResponse(true) , m_user{user}
{
}

User UserLoginResponse::GetUser() const
{
    return m_user;
}
