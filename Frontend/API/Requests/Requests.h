#pragma once
#include <string>
#include <cpr/cpr.h>
#include <crow/json.h>
#include "../../API/ApiEndpoints/ApiEndpoints.h"

class Requests {
public:
    static cpr::Response RegisterUser(const std::string& surname, const std::string& givenName, const std::string& username, const std::string& password);
    static cpr::Response LoginUser(const std::string& username, const std::string& password);
    static cpr::Response getUserInfo(const int userId);
    static cpr::Response createLobby(const int userId, const bool isPrivate, const int lobbyType);
    static cpr::Response joinLobby(const int userId, const int lobbyId);
    static cpr::Response leaveLobby(const int userId, const int lobbyId);
    static cpr::Response lobbyStatus(const int lobbyId);
    static cpr::Response updateLobby(const int lobbyId, const int lobbyType, const bool isPrivate);
    static cpr::Response joinRandomLobby(const int userId);
    static cpr::Response startGame(const int lobbyId);
    static cpr::Response getRunningGameForUser(const int userId);
    static cpr::Response getRunningGameStatus(const int gameId);
private:
    static cpr::Response SendRequest(const std::string& url, const crow::json::wvalue& payload, const std::string& method);
};