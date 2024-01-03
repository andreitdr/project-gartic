#pragma once

#include "../../../Infrastructure/UserLogin/UserLoginRequest.h"
#include "../../../Infrastructure/UserLogin/UserLoginResponse.h"

class UserLoginContext
{
public:
    static UserLoginResponse Login(const UserLoginRequest &request);

private:
    static bool UserExists(const Credentials &credentials);
    static bool PasswordMatches(const Credentials &credentials);
};