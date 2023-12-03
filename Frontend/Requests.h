#pragma once
#include <string>
#include <cpr/cpr.h>
#include <crow/json.h>

class Requests {
public:
    static cpr::Response RegisterUser(const std::string& surname, const std::string& givenName, const std::string& username, const std::string& password);
    static cpr::Response LoginUser(const std::string& username, const std::string& password);
    static cpr::Response CreateLobby(const int lobbyId,const int userId);
};