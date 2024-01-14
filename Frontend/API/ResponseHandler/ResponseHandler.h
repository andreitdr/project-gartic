#pragma once
#include <crow/json.h>
#include <functional>
#include "../../Utils/LobbyData/LobbyData.h"
#include "../../Utils/GameData/GameData.h"
#include "../../Utils/UserInfoCache/UserInfoCache.h"

class ResponseHandler
{
public:
	void processLoginResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback);
	void processRegisterResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback);
	void processGetUserInfoResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback);
	void processCreateLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const LobbyData&)> callback);
	void processJoinLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback);
	void processLeaveLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback);
	void processLobbyStatusResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const LobbyData&)> callback);
	void processUpdateLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&)> callback);
	void processJoinRandomLobbyResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback);
	void processStartGameResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback);
	void processGetRunningGameForUser(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback);
	void processGameStatusResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const GameData&)> callback);
};

