#include "Requests.h"

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

cpr::Response Requests::LoginUser(const std::string& username, const std::string& password)
{
    crow::json::wvalue payload;
	payload["username"] = username;
	payload["password"] = password;

	std::string json_payload = payload.dump();

	cpr::Response r = cpr::Post(cpr::Url{ "http://localhost:18080/user/login" },
        		cpr::Body{ json_payload },
        		cpr::Header{ {"Content-Type", "application/json"} });

	return r;
}

cpr::Response Requests::CreateLobby(const int lobbyId, const int userId)
{
    crow::json::wvalue payload;
    payload["Id"] = lobbyId;
    payload["User"] = userId;

    std::string json_payload = payload.dump();

    cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/game/create_lobby" },
        cpr::Body{ json_payload },
        cpr::Header{ {"Content-Type", "application/json"} });

    return r;
}
