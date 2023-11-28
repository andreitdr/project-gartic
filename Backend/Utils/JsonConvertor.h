﻿#pragma once

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
    CONV_FUNCTION ConvertUser(const User& user, bool hasID);

    CONV_FUNCTION ConvertBaseResponse(const BaseResponse& response);
    
    template <typename T>
    CONV_FUNCTION ConvertFromVector(const std::vector<T>& vector);
};

template <typename T>
inline WJSON JsonConvertor::ConvertFromVector(const std::vector<T>& vector)
{
    WJSON json;
    for(int i = 0; i < vector.size(); i++)
    {
        json[i] = vector[i];
    }

    return json;
}

inline WJSON JsonConvertor::ConvertCredentials(const Credentials& c)
{
    WJSON json;
    json["username"] = c.m_username;
    json["password"] = c.m_hashedPassword;

    return json;
}

inline WJSON JsonConvertor::ConvertUser(const User& user, bool hasID = false)
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

    json["ResponseState"] = response.m_successState;
    json["ResponseMessage"] = response.m_messages;

    return json;
}
