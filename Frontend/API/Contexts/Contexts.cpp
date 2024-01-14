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

void Contexts::updateLobby(int lobbyId, int lobbyType, bool isPrivate, std::function<void(bool, const std::string&)> callback)
{
	auto response = requests.updateLobby(lobbyId, lobbyType, isPrivate);
	if (response.status_code != 200)
	{
		callback(false, "Server error");
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processUpdateLobbyResponse(response_json, [callback](bool success, const std::string& message)
		{
			callback(success, message);
		});
}

void Contexts::joinRandomLobby(int userId, std::function<void(bool, const std::string&, int)> callback)
{
	auto response = requests.joinRandomLobby(userId);
	if (response.status_code != 200)
	{
		callback(false, "Server error", -1);
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processJoinRandomLobbyResponse(response_json, [callback](bool success, const std::string& message, int lobbyId)
		{
		callback(success, message, lobbyId);
	});
}

void Contexts::startGame(int lobbyId, std::function<void(bool, const std::string&, int)> callback)
{
	auto response = requests.startGame(lobbyId);
	if (response.status_code != 200)
	{
		callback(false, "Server error", -1);
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processStartGameResponse(response_json, [callback](bool success, const std::string& message, int gameId)
		{
			callback(success, message, gameId);
		});
}

void Contexts::getRunningGameForUser(int userId, std::function<void(bool, const std::string&, int)> callback)
{
	auto response = requests.getRunningGameForUser(userId);
	if (response.status_code != 200)
	{
		callback(false, "Server error", -1);
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processGetRunningGameForUser(response_json, [callback](bool success, const std::string& message, int gameId)
		{
			callback(success, message, gameId);
		});
}

void Contexts::getRunningGameStatus(int gameId, std::function<void(bool, const std::string&, const GameData&)> callback)
{
	std::thread([this, gameId, callback]() {
		auto response = requests.getRunningGameStatus(gameId);
		if (response.status_code != 200) {
			QMetaObject::invokeMethod(qApp, [callback]() {
				callback(false, "Server error", GameData());
				});
			return;
		}

		auto response_json = crow::json::load(response.text);
		handler.processGameStatusResponse(response_json, [callback](bool success, const std::string& message, const GameData& gameData) {
			QMetaObject::invokeMethod(qApp, [callback, success, message, gameData]() {
				callback(success, message, gameData);
				});
			});
		}).detach();
}

void Contexts::checkWord(int gameId, int userId, const std::string& word, std::function<void(bool, const std::string&)> callback)
{
	auto response = requests.checkWord(gameId, userId, word);
	if (response.status_code != 200)
	{
		callback(false, "Server error");
		return;
	};

	auto response_json = crow::json::load(response.text);
	handler.processCheckWord(response_json, [callback](bool success, const std::string& message)
		{
			callback(success, message);
		});
}

void Contexts::getChatMessages(int gameId, std::function<void(bool, const std::string&, const std::vector<std::string>&)> callback)
{
	std::thread ([this, gameId, callback]() {
		auto response = requests.getChatMessages(gameId);
		if (response.status_code != 200) {
			QMetaObject::invokeMethod(qApp, [callback]() {
				callback(false, "Server error", std::vector<std::string>());
				});
			return;
		}

		auto response_json = crow::json::load(response.text);
		handler.processGetChatMessages(response_json, [callback](bool success, const std::string& message, const std::vector<std::string>& messages) {
			QMetaObject::invokeMethod(qApp, [callback, success, message, messages]() {
				callback(success, message, messages);
				});
			});
		}).detach();
}

void Contexts::sendDrawing(int gameId, const std::string& drawing, std::function<void(bool, const std::string&)> callback)
{
	std::thread ([this, gameId, drawing, callback]() {
		auto response = requests.sendDrawing(gameId, drawing);
		if (response.status_code != 200) {
			QMetaObject::invokeMethod(qApp, [callback]() {
				callback(false, "Server error");
				});
			return;
		}

		auto response_json = crow::json::load(response.text);
		handler.processSendDrawing(response_json, [callback](bool success, const std::string& message) {
			QMetaObject::invokeMethod(qApp, [callback, success, message]() {
				callback(success, message);
				});
			});
		}).detach();
}

void Contexts::getDrawing(int gameId, std::function<void(bool, const std::string&, const std::string&)> callback)
{
	std::thread ([this, gameId, callback]() {
	auto response = requests.getDrawing(gameId);
		if (response.status_code != 200) {
			QMetaObject::invokeMethod(qApp, [callback]() {
				callback(false, "Server error", "");
				});
			return;
		}

		auto response_json = crow::json::load(response.text);
		handler.processGetDrawing(response_json, [callback](bool success, const std::string& message, const std::string& drawing) {
			QMetaObject::invokeMethod(qApp, [callback, success, message, drawing]() {
				callback(success, message, drawing);
				});
			});
		}).detach();
}
