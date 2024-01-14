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

cpr::Response Requests::createLobby(const int userId, const bool isPrivate, const int lobbyType)
{
    crow::json::wvalue payload;
    payload["userId"] = userId;
    payload["lobbyType"] = lobbyType;
    payload["isPrivateLobby"] = isPrivate;
    return SendRequest(ApiEndpoints::CREATE_LOBBY, payload, "POST");
}

cpr::Response Requests::joinLobby(const int userId, const int lobbyId)
{
    crow::json::wvalue payload;
    payload["lobbyId"] = lobbyId;
    payload["userId"] = userId;
    return SendRequest(ApiEndpoints::JOIN_LOBBY, payload, "POST");
}

cpr::Response Requests::leaveLobby(const int userId, const int lobbyId)
{
    crow::json::wvalue payload;
    payload["lobbyId"] = lobbyId;
    payload["userId"] = userId;
    return SendRequest(ApiEndpoints::LEAVE_LOBBY, payload, "POST");
}

cpr::Response Requests::lobbyStatus(const int lobbyId)
{
    crow::json::wvalue payload;
    payload["lobbyId"] = lobbyId;
    return SendRequest(ApiEndpoints::LOBBY_STATUS, payload, "GET");
}

cpr::Response Requests::updateLobby(const int lobbyId, const int lobbyType, const bool isPrivate)
{
    crow::json::wvalue payload;
    payload["lobbyId"] = lobbyId;
    payload["lobbyType"] = lobbyType;
    payload["IsPrivate"] = isPrivate;
	return SendRequest(ApiEndpoints::UPDATE_LOBBY, payload, "POST");
}

cpr::Response Requests::joinRandomLobby(const int userId)
{
    crow::json::wvalue payload;
	payload["userId"] = userId;
	return SendRequest(ApiEndpoints::JOIN_RANDOM_LOBBY, payload, "POST");
}

cpr::Response Requests::startGame(const int lobbyId)
{
    crow::json::wvalue payload;
    payload["lobbyId"] = lobbyId;
    return SendRequest(ApiEndpoints::START_GAME, payload, "POST");
}

cpr::Response Requests::getRunningGameForUser(const int userId)
{
    crow::json::wvalue payload;
    payload["userId"] = userId;
    return SendRequest(ApiEndpoints::GET_RUNNING_GAME_FOR_USER, payload, "GET");
}

cpr::Response Requests::getRunningGameStatus(const int gameId)
{
    crow::json::wvalue payload;
    payload["gameId"] = gameId;
    return SendRequest(ApiEndpoints::GET_RUNNING_GAME_STATUS, payload, "GET");
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

