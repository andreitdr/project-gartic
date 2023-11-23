#pragma once
#include "../../SqlDatabase/SqlDatabase.h"

export module UserLoginContext;

export import UserLoginRequest;
export import UserLoginResponse;
using namespace sqlite_orm;
export class UserLoginContext
{
public:
    static UserLoginResponse Login(const UserLoginRequest& request);

private:
    static bool UserExists(const Credentials& credentials);
    static bool PasswordMatches(const Credentials& credentials);
};

UserLoginResponse UserLoginContext::Login(const UserLoginRequest& request)
{
    Credentials credentials = request.GetCredentials();
    if(!UserExists(credentials))
        return UserLoginResponse("Inexistent user", false);

    if (!PasswordMatches(credentials))
        return UserLoginResponse("Incorrect password", false);
    
    
    return UserLoginResponse("Success", true);
}

bool UserLoginContext::UserExists(const Credentials& credentials)
{
    return SqlDatabase::ExistsModel(credentials);
}

bool UserLoginContext::PasswordMatches(const Credentials& credentials)
{
    auto whereCondition = where((c(&Credentials::m_username) == credentials.m_username) and
        (c(&Credentials::m_hashedPassword) == credentials.m_hashedPassword));
    
    return SqlDatabase::Exists<Credentials>(whereCondition);
    
}

