export module infosaver;

import <string>;
import <format>;

export class InfoSaver
{
public:
	static void SetPoints(const size_t user_id, int point_number);
	static int GetPoints(const size_t user_id);
	static void SetUsername(const size_t user_id, const std::string username);
	static std::string GetUsername(const size_t user_id);
	static std::string GetFile(const std::string& file_prefix, const std::string& file_suffix = ".json");
	static void InitializeUser(const size_t user_id);
};

