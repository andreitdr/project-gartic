#pragma once
#include "Utils/JsonConvertor.h"

#include <crow.h>
import UserLoginContext;


inline WJSON UserLogin(crow::json::rvalue jsonInput)
{
    Credentials credentials;

    credentials.m_username = jsonInput["username"].s();
    credentials.m_hashedPassword = jsonInput["password"].s();

    auto response = UserLoginContext::Login(UserLoginRequest(credentials));

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(response);
    return JResponse;
}