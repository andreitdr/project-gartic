#pragma once

#define WJSON crow::json::wvalue
#define CONV_FUNCTION static WJSON
import BaseResponse;

#include <crow.h>
import Credentials;
import User;


class JsonConvertor
{
public:
    CONV_FUNCTION ConvertCredentials(const Credentials& c);
    CONV_FUNCTION ConvertUser(const UserStructModel& user, bool hasID);

    CONV_FUNCTION ConvertBaseResponse(const BaseResponse& response);

    
};

inline WJSON JsonConvertor::ConvertCredentials(const Credentials& c)
{
    WJSON json;
    json["username"] = c.m_username;
    json["password"] = c.m_hashedPassword;

    return json;
}

inline WJSON JsonConvertor::ConvertUser(const UserStructModel& user, bool hasID = false)
{
    WJSON json;
    json["username"] = user.m_username;
    json["givenName"] = user.m_givenName;
    json["surname"] = user.m_surname;
    if(hasID)
        json["userID"] = user.m_user_id;

    return json;
}

inline WJSON JsonConvertor::ConvertBaseResponse(const BaseResponse& response)
{
    WJSON json;
    json["SuccessState"] = response.m_successState;
    json["ResponseMessages"] = response.m_messages;

    return json;
}
