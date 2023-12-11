#include "Requests.h"

cpr::Response Requests::RegisterUser(const std::string& surname, const std::string& givenName, const std::string& username, const std::string& password)
{
    crow::json::wvalue payload;
    payload["surname"] = surname;
    payload["givenName"] = givenName;
    payload["username"] = username;
    payload["password"] = password;
    return SendRequest(ApiEndpoints::REGISTER_USER, payload, "POST");
}

cpr::Response Requests::LoginUser(const std::string& username, const std::string& password)
{
    crow::json::wvalue payload;
	payload["username"] = username;
	payload["password"] = password;
    return SendRequest(ApiEndpoints::LOGIN_USER, payload, "GET");
}

cpr::Response Requests::getUserInfo(const int userId)
{
    crow::json::wvalue payload;
    payload["userID"] = userId;
    return SendRequest(ApiEndpoints::GET_USER_INFO, payload, "GET");
}

cpr::Response Requests::SendRequest(const std::string& url, const crow::json::wvalue& payload, const std::string& method)
{
    std::string json_payload = payload.dump();
    cpr::Header header = { {"Content-Type", "application/json"} };

    if (method == "GET") {
        return cpr::Get(cpr::Url{ url }, cpr::Body{ json_payload }, header);
    }
    else if (method == "POST") {
        return cpr::Post(cpr::Url{ url }, cpr::Body{ json_payload }, header);
    }
    return cpr::Response();
}

