#pragma once
#include "../../SqlDatabase/SqlDatabase.h"

export module UserLoginContext;

export import UserLoginRequest;
export import UserLoginResponse;

export class UserLoginContext
{
public:
    static UserLoginResponse Login(const UserLoginRequest& request);

private:
    static bool UserExists(const Credentials& credentials);
};

UserLoginResponse UserLoginContext::Login(const UserLoginRequest& request)
{
    Credentials credentials = request.GetCredentials();
    if(!UserExists(credentials))
        return UserLoginResponse("Incorrect user credentials", false);

    return UserLoginResponse(true); 
}

bool UserLoginContext::UserExists(const Credentials& credentials)
{
    return SqlDatabase::Exists(credentials);
}

