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
	void createLobby(int userId, std::function<void(bool, const std::string&, const LobbyData&)> callback);
	void joinLobby(int userId, int lobbyId, std::function<void(bool, const std::string&)> callback);
	void leaveLobby(int userId, int lobbyId, std::function<void(bool, const std::string&)> callback);
	void lobbyStatus(int lobbyId, std::function<void(bool, const std::string&, const LobbyData&)> callback);
private:
	ResponseHandler handler;
	Requests requests;
};