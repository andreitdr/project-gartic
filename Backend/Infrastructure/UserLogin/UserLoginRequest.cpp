#include "UserLoginRequest.h"

UserLoginRequest::UserLoginRequest(const Credentials& userCredentails) : m_userCredentials(userCredentails)
{
}

Credentials UserLoginRequest::GetCredentials() const
{
    return m_userCredentials;
}
