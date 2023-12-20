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
    CONV_FUNCTION ConvertUser(const User& user, bool hasID);

    CONV_FUNCTION ConvertBaseResponse(const BaseResponse& response);
    
    template <typename T>
    CONV_FUNCTION ConvertFromVector(const std::vector<T>& vector);

    template<typename T>
    static std::vector<T> ConvertToVector(const std::string& jsonStr);

    template<typename T>
    static std::vector<T> ConvertToVector(const crow::json::rvalue& json);
};

template <typename T>
std::vector<T> JsonConvertor::ConvertToVector(const std::string& jsonStr)
{
    if(jsonStr == "") return std::vector<T>();
    if(jsonStr == "null") return std::vector<T>();
    const crow::json::rvalue json = crow::json::load(jsonStr);
    return ConvertToVector<T>(json);
}

template <typename T>
std::vector<T> JsonConvertor::ConvertToVector(const crow::json::rvalue& json)
{
    std::vector<T> vector;
    for(int i = 0; i < json.size(); i++)
    {
        vector.push_back(static_cast<T>(json[i]));
    }

    return vector;
}

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
