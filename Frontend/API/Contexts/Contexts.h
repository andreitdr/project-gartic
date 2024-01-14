#pragma once
#include "../Requests/Requests.h"
#include "../ResponseHandler/ResponseHandler.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include <functional>

class Contexts
{
public:
	void registerUser(const std::string& surname, const std::string& givenName, const std::string& username, const std::string& password, std::function<void(bool, const std::string&)> callback);
	void loginUser(const std::string& username, const std::string& password, std::function<void(bool, const std::string&)> callback);
	void getUserInfo(int userId, std::function<void(bool, const std::string&, const UserInfo&)> callback);
	void createLobby(int userId, bool isPrivate, int lobbyType, std::function<void(bool, const std::string&, const LobbyData&)> callback);
	void joinLobby(int userId, int lobbyId, std::function<void(bool, const std::string&)> callback);
	void leaveLobby(int userId, int lobbyId, std::function<void(bool, const std::string&)> callback);
	void lobbyStatus(int lobbyId, std::function<void(bool, const std::string&, const LobbyData&)> callback);
	void updateLobby(int lobbyId, int lobbyType, bool isPrivate, std::function<void(bool, const std::string&)> callback);
	void joinRandomLobby(int userId, std::function<void(bool, const std::string&, int)> callback);
	void startGame(int lobbyId, std::function<void(bool, const std::string&, int)> callback);
	void getRunningGameForUser(int userId, std::function<void(bool, const std::string&, int)> callback);
	void getRunningGameStatus(int gameId, std::function<void(bool, const std::string&, const GameData&)> callback);
	void checkWord(int gameId, int userId, const std::string& word, std::function<void(bool, const std::string&)> callback);
	void getChatMessages(int gameId, std::function<void(bool, const std::string&, const std::vector<std::string>&)> callback);
	void sendDrawing(int gameId, const std::string& drawing, std::function<void(bool, const std::string&)> callback);
	void getDrawing(int gameId, std::function<void(bool, const std::string&, const std::string&)> callback);
private:
	ResponseHandler handler;
	Requests requests;
};