#include "Contexts.h"
#include <thread>
#include <QApplication>


void Contexts::registerUser(const std::string& surname, const std::string& givenName, const std::string& username, const std::string& password, std::function<void(bool, const std::string&)> callback)
{
	auto response = requests.RegisterUser(surname, givenName, username, password);
	if (response.status_code != 200) 
	{
		callback(false, "Server error");
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processRegisterResponse(response_json, [callback](bool success, const std::string& message, int new_user_id) 
	{
		callback(success, message);
	});
}

void Contexts::loginUser(const std::string& username, const std::string& password, std::function<void(bool, const std::string&)> callback)
{
	auto response = requests.LoginUser(username, password);
	if (response.status_code != 200) 
	{
		callback(false, "Server error");
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processLoginResponse(response_json, [callback](bool success, const std::string& message, const UserInfo& userInfo) 
	{
		CurrentUser& user = CurrentUser::getInstance();
		user.setUserId(userInfo.getUserId());
		user.setUsername(userInfo.getUsername());
		user.setGivenName(userInfo.getGivenName());
		user.setSurname(userInfo.getSurname());
		callback(success, message);
	});
}

void Contexts::getUserInfo(int userId, std::function<void(bool, const std::string&, const UserInfo&)> callback)
{
	auto response = requests.getUserInfo(userId);
	if (response.status_code != 200)
	{
		callback(false, "Server error", UserInfo());
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processGetUserInfoResponse(response_json, [callback](bool success, const std::string& message, const UserInfo& userInfo)
		{
		callback(success, message, userInfo);
	});
}

void Contexts::createLobby(int userId, bool isPrivate, int lobbyType, std::function<void(bool, const std::string&, const LobbyData&)> callback)
{
	auto response = requests.createLobby(userId,isPrivate,lobbyType);
	if (response.status_code != 200)
	{
		callback(false, "Server error",LobbyData());
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processCreateLobbyResponse(response_json, [callback](bool success, const std::string& message, const LobbyData& lobbyData)
		{
		callback(success, message, lobbyData);
	});
}

void Contexts::joinLobby(int userId, int lobbyId, std::function<void(bool, const std::string&)> callback)
{
	auto response = requests.joinLobby(userId, lobbyId);
	if (response.status_code != 200)
	{
		callback(false, "Server error");
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processJoinLobbyResponse(response_json, [callback](bool success, const std::string& message)
		{
		callback(success, message);
	});
}

void Contexts::leaveLobby(int userId, int lobbyId, std::function<void(bool, const std::string&)> callback)
{
	auto response = requests.leaveLobby(userId, lobbyId);
	if (response.status_code != 200)
	{
		callback(false, "Server error");
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processLeaveLobbyResponse(response_json, [callback](bool success, const std::string& message)
		{
		callback(success, message);
	});
}

void Contexts::lobbyStatus(int lobbyId, std::function<void(bool, const std::string&, const LobbyData&)> callback) 
{
	std::thread([this, lobbyId, callback]() {
		auto response = requests.lobbyStatus(lobbyId);
		if (response.status_code != 200) {
			QMetaObject::invokeMethod(qApp, [callback]() {
				callback(false, "Server error", LobbyData());
				});
			return;
		}

		auto response_json = crow::json::load(response.text);
		handler.processLobbyStatusResponse(response_json, [callback](bool success, const std::string& message, const LobbyData& lobbyData) {
			QMetaObject::invokeMethod(qApp, [callback, success, message, lobbyData]() {
				callback(success, message, lobbyData);
				});
			});
		}).detach();
}
