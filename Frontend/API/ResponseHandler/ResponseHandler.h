#pragma once
#include <crow/json.h>
#include <functional>
#include "../../Utils/UserInfo/UserInfo.h"
#include "../../Utils/LobbyData/LobbyData.h"

class ResponseHandler
{
public:
	void processLoginResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback);
	void processRegisterResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback);
	void processGetUserInfoResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback);
	void processCreateLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const LobbyData&)> callback);
	void processJoinLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback);
	void processLeaveLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback);
	void processLobbyStatResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const LobbyData&)> callback);
};

