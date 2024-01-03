#pragma once
#include "../../DataTypes/User/Credentials.h"

class UserLoginRequest
{
public:
    UserLoginRequest(const Credentials& userCredentails);
    Credentials GetCredentials() const;

private:
    Credentials m_userCredentials;
};
