#include "UserRegistrationResponse.h"

UserRegistrationResponse::UserRegistrationResponse(const std::string& message, bool state)
{
    AppendMessage(message);
    m_successState = state;
}

UserRegistrationResponse::UserRegistrationResponse() : BaseResponse()
{
}

void UserRegistrationResponse::SetUser(const User& user)
{
    m_user = user;
}

std::optional<User> UserRegistrationResponse::GetUser() const
{
    return m_user;
}
