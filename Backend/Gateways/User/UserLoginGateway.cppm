﻿export module UserLoginGateway;

export import UserLoginRequest;
export import UserLoginResponse;
export import sqlmodule;

export import logging;

import <iostream>;
import <string>;
import <format>;

export class UserLoginGateway
{
public:
    UserLoginResponse Login(const UserLoginRequest& request);
private:
    bool UserExists(const credentials& user);
};

UserLoginResponse UserLoginGateway::Login(const UserLoginRequest& request)
{
    Logger logger = Logger(std::cout);
    UserLoginResponse response = UserLoginResponse();
    const credentials object = request.GetObject();

    logger.Log(std::format("Searching for user {}", request.GetObject().m_username));
    if(!UserExists(object))
    {
        return UserLoginResponse("The user could not be found !", false);
    }

    
    logger.Log(std::format("Getting database..."));
    auto database = SqlDatabase::GetDatabase();

    std::string sql = "SELECT * FROM Credentials where Username=@username"; 

    response.SetCredentials(database.GetData<credentials>(sql));
    response.SetResponseState(true);
    logger.Log(std::format("Transaction finished !"));
    return response;
}

bool UserLoginGateway::UserExists(const credentials& user)
{
    
    auto database = SqlDatabase::GetDatabase();
    if(database.RecordExists(user)) return true;
    return false;
}




