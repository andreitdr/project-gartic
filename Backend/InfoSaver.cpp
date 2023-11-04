#include "InfoSaver.h"
#include <format>
#include <fstream>

std::string InfoSaver::getFile(const std::string& file_prefix, const std::string& file_suffix)
{
	std::string file = file_prefix + file_suffix;
	return file;
}
void InfoSaver::setPoints(const size_t user_id, int point_number)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(getFile(user_as_string));
	users = json::parse(i);
	std::ofstream f(getFile(user_as_string));
	users["Points"] = point_number;
	f << std::setw(4) << users << std::endl;
}


int InfoSaver::getPoints(const size_t user_id)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(getFile(user_as_string));
	users = json::parse(i);
	return users["Points"].template get<int>();
}
void InfoSaver::setUsername(const size_t user_id,const std::string username)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(getFile(user_as_string));
	users = json::parse(i);
	std::ofstream f(getFile(user_as_string));
	users["Username"] = username;
	f << std::setw(4) << users << std::endl;
}

std::string InfoSaver::getUsername(const size_t user_id)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(getFile(user_as_string));
	users = json::parse(i);
	return users["Username"].template get<std::string>();
}

void InfoSaver::initializeUser(const size_t user_id)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ofstream o(getFile(user_as_string));
	const int starting_points = 0;
	const std::string empty_username = "";
	users["Username"] = empty_username;
	users["Points"] = starting_points;
	o << std::setw(4) << users << std::endl;
}
