#include "NetworkRequests.h"

cpr::Response Requests::RegisterUser(const std::string& surname, const std::string& givenName, const std::string& username, const std::string& password)
{
    crow::json::wvalue payload;
    payload["surname"] = surname;
    payload["givenName"] = givenName;
    payload["username"] = username;
    payload["password"] = password;

    std::string json_payload = payload.dump();

    cpr::Response r = cpr::Post(cpr::Url{ "http://localhost:18080/user/register" },
        cpr::Body{ json_payload },
        cpr::Header{ {"Content-Type", "application/json"} });

    return r;
}
