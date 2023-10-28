#pragma once
#include <string>
#include <format>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
class InfoSaver
{public:
	static std::string getFile(std::string file_prefix,const std::string file_suffix = ".json");
	static void initializeUser(size_t user_id);
};

