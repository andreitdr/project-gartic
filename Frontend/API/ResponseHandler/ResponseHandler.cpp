#include "ResponseHandler.h"

void ResponseHandler::processLoginResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback)
{
    if (!response) {
        callback(false, "Invalid response format", UserInfo());
        return;
    }

    bool success = response["ResponseState"].b();
    std::string message = response["ResponseMessage"][0].s();

    if (success) {
        std::string username = response["UserData"]["username"].s();
        std::string givenName = response["UserData"]["givenName"].s();
        std::string surname = response["UserData"]["surname"].s();
        int userId = response["UserData"]["userID"].i();
        UserInfo userInfo(username, givenName, surname, userId);
        callback(true, message, userInfo);
    }
    else {
        callback(false, message, UserInfo());
    }
}
