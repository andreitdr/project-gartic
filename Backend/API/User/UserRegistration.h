#pragma once

#include <crow.h>
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/User/Registration/UserRegistrationContext.h"

inline WJSON RegisterUser(const crow::json::rvalue& request)
{
    User user;
    user.m_surname   = request["surname"].s();
    user.m_givenName = request["givenName"].s();
    user.m_username  = request["username"].s();
    user.m_user_id   = -1;

    Credentials credentials;
    credentials.m_username       = user.m_username;
    credentials.m_hashedPassword = request["password"].s();

    UserRegistrationRequest userRegistrationRequest = UserRegistrationRequest(user, credentials);
    UserRegistrationResponse response               = UserRegistrationContext::RegisterUser(userRegistrationRequest);

    WJSON responseJson        = JsonConvertor::ConvertBaseResponse(response);
    responseJson["NewUserID"] = response.GetUser().value().m_user_id;

    return responseJson;
}
