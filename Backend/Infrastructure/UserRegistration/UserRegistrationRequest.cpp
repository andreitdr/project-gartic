#include "UserRegistrationRequest.h"

UserRegistrationRequest::UserRegistrationRequest(const User& user, const Credentials& userCredentials) :
    m_userCredentials(userCredentials), m_user(user)
{
}

Credentials UserRegistrationRequest::GetCredentials() const
{
    return m_userCredentials;
}

User UserRegistrationRequest::GetUser() const
{
    return m_user;
}
