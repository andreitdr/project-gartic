import UserRegistrationContext;

#pragma once
#include <crow.h>


inline crow::json::wvalue RegisterUser(crow::json::rvalue& request)
{
    UserStructModel user;
    user.m_surname = request["surname"].s();
    user.m_givenName = request["givenName"].s();
    user.m_username = request["username"].s();
    user.m_user_id = -1;
    
    UserRegistrationRequest userRegistrationRequest = UserRegistrationRequest(user);
    UserRegisterResponse response = UserRegistrationContext::RegisterUser(userRegistrationRequest);

    crow::json::wvalue responseJson = crow::json::wvalue();
    responseJson["responseStatus"] = response.GetResponseState();
    responseJson["responseMessage"] = response.GetResponseMessages();

    return responseJson;
}