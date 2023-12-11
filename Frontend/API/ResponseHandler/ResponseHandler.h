#pragma once
#include <crow/json.h>
#include <functional>
#include "../../Utils/UserInfo/UserInfo.h"

class ResponseHandler
{
public:
	void processLoginResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, const UserInfo&)> callback);
	void processRegisterResponse(const crow::json::rvalue& response, std::function<void(bool, const std::string&, int)> callback);
};

