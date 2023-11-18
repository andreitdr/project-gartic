#pragma once
import UserRegistrationContext;

#include <crow.h>

inline crow::json::wvalue RegisterUser(crow::json::rvalue& request)
{
    UserStructModel user;
    user.m_surname = request["surname"].s();
    user.m_givenName = request["givenName"].s();
    user.m_username = request["username"].s();
    user.m_user_id = -1;

    Credentials credentials;
    credentials.m_username = user.m_username;
    credentials.m_hashedPassword = request["password"].s();
    
    UserRegistrationRequest userRegistrationRequest = UserRegistrationRequest(user, credentials);
    UserRegistrationResponse response = UserRegistrationContext::RegisterUser(userRegistrationRequest);

    crow::json::wvalue responseJson = crow::json::wvalue();
    responseJson["SuccessState"] = response.m_successState;
    responseJson["ResponseMessages"] = response.m_messages;

    return responseJson;
}