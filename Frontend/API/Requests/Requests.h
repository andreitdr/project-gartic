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
private:
    static cpr::Response SendRequest(const std::string& url, const crow::json::wvalue& payload, const std::string& method);
};