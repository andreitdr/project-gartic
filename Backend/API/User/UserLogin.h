#pragma once

#include <crow.h>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/User/Login/UserLoginContext.h"


inline WJSON UserLogin(const crow::json::rvalue& jsonInput)
{
    Credentials credentials;

    credentials.m_username       = jsonInput["username"].s();
    credentials.m_hashedPassword = jsonInput["password"].s();

    UserLoginContext context {};
    UserLoginResponse response = context.HandleRequest(UserLoginRequest(credentials));

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(response);
    JResponse["UserData"] = JsonConvertor::ConvertUser(response.GetUser(), true);
    return JResponse;
}
