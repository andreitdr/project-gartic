#include "ResponseHandler.h"
#include "../../Utils/CurrentUser/CurrentUser.h"

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

void ResponseHandler::processCreateLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const LobbyData&)> callback)
{
    if (!response) {
        callback(false, "Invalid response format", LobbyData());
        return;
    }

    bool success = response["ResponseState"].b();
    std::string message;
        if (response["ResponseMessage"].size() > 0)
            message = response["ResponseMessage"][0].s();
        else
    message = "";

    if (success) {
        LobbyData lobbyData;
        lobbyData.SetLobbyID(response["Lobby"]["Id"].i());
        int userId = response["Lobby"]["LeaderId"].i();
        UserInfo admin;
        CurrentUser& user = CurrentUser::getInstance();
        admin.setUsername(user.getUsername());
        admin.setGivenName(user.getGivenName());
        admin.setSurname(user.getSurname());
        admin.setUserId(userId);
        lobbyData.SetLobbyAdmin(admin);

        auto& playerListJson = response["Lobby"]["PlayerList"];
        for (const auto& playerIdJson : playerListJson) {
            UserInfo player = UserInfo::GetUserInfoFromServer(playerIdJson.i());
            lobbyData.AddUser(player);
        }

        callback(true, message, lobbyData);
    }
    else {
        callback(false, message, LobbyData());
    }
}

void ResponseHandler::processJoinLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback)
{
    if (!response) {
        callback(false, "Invalid response format");
        return;
    }

    bool success = response["ResponseState"].b();
    std::string message;
    if (response["ResponseMessage"].size() > 0)
        message = response["ResponseMessage"][0].s();
    else
        message = "";

    callback(success, message);
}

void ResponseHandler::processLeaveLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback)
{
    if (!response) {
        callback(false, "Invalid response format");
        return;
    }

    bool success = response["ResponseState"].b();
    std::string message;
    if (response["ResponseMessage"].size() > 0)
        message = response["ResponseMessage"][0].s();
    else
        message = "";

    callback(success, message);
}

void ResponseHandler::processLobbyStatusResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const LobbyData&)> callback)
{
    if (!response) {
		callback(false, "Invalid response format", LobbyData());
		return;
	}

	bool success = response["ResponseState"].b();
	std::string message;
	if (response["ResponseMessage"].size() > 0)
		message = response["ResponseMessage"][0].s();
	else
		message = "";

    if (success) {
		LobbyData lobbyData;
		lobbyData.SetLobbyID(response["Lobby"]["Id"].i());
		int userId = response["Lobby"]["LeaderId"].i();
		UserInfo admin = UserInfo::GetUserInfoFromServer(userId);
		lobbyData.SetLobbyAdmin(admin);

		auto& playerListJson = response["Lobby"]["PlayerList"];
        for (const auto& playerIdJson : playerListJson) {
			UserInfo player = UserInfo::GetUserInfoFromServer(playerIdJson.i());
			lobbyData.AddUser(player);
		}

		callback(true, message, lobbyData);
	}
    else {
		callback(false, message, LobbyData());
	}
}
