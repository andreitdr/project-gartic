#pragma once

#include <crow.h>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/User/Login/UserLoginContext.h"


inline WJSON UserLogin(crow::json::rvalue jsonInput)
{
    Credentials credentials;

    credentials.m_username       = jsonInput["username"].s();
    credentials.m_hashedPassword = jsonInput["password"].s();

    auto response = UserLoginContext::Login(UserLoginRequest(credentials));

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(response);
    return JResponse;
}
