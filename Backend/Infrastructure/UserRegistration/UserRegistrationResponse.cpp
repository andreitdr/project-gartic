#include "UserRegistrationResponse.h"

UserRegistrationResponse::UserRegistrationResponse(const std::string& message, bool state)
{
    AppendMessage(message);
    m_successState = state;
}

UserRegistrationResponse::UserRegistrationResponse(bool state) : BaseResponse(state)
{
}

UserRegistrationResponse::UserRegistrationResponse(const User& user) : BaseResponse(true), m_user{user}
{
}

void UserRegistrationResponse::SetUser(const User& user)
{
    m_user = user;
}

User UserRegistrationResponse::GetUser() const
{
    return m_user;
}
