#pragma once

#include "../../DataTypes/User/Credentials.h"
#include "../../DataTypes/User/User.h"

class UserRegistrationRequest
{
public:
    UserRegistrationRequest(const User& user, const Credentials& userCredentials);
    Credentials GetCredentials() const;
    User GetUser() const;

private:
    Credentials m_userCredentials;
    User m_user;
};
