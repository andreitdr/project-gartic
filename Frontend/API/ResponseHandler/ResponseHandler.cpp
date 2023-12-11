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

void ResponseHandler::processRegisterResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback)
{
    if (!response) {
        callback(false, "Invalid response format", -1);
        return;
    }

    bool success = response["ResponseState"].b();
    std::string message = response["ResponseMessage"][0].s();
    int new_user_id = -1;

    if (success) {
        new_user_id = response["NewUserID"].i();
    }

    callback(success, message, new_user_id);
}

void ResponseHandler::processGetUserInfoResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback)
{
	if (!response) {
		callback(false, "Invalid response format", UserInfo());
		return;
	}

	bool success = response["ResponseState"].b();
    std::string message = "Success";

	if (success) {
		std::string username = response["user"]["username"].s();
		std::string givenName = response["user"]["givenName"].s();
		std::string surname = response["user"]["surname"].s();
		int userId = response["user"]["id"].i();
		UserInfo userInfo(username, givenName, surname, userId);
		callback(true, message, userInfo);
	}
	else {
		callback(false, message, UserInfo());
	}
}
