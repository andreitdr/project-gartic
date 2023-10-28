#pragma once
#include <string>
#include <format>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class InfoSaver
{public:
	static void setPoints(size_t user_id, int point_number);
	static int getPoints(size_t user_id);
	static void setUsername(size_t user_id, std::string username);
	static std::string getUsername(size_t user_id);
	static std::string getFile(std::string file_prefix,const std::string file_suffix = ".json");
	static void initializeUser(size_t user_id);
};

