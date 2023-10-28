#include "InfoSaver.h"
#include <format>
#include <fstream>

std::string InfoSaver::getFile(std::string file_prefix, const std::string file_suffix)
{
	std::string file = file_prefix + file_suffix;
	return file;
}

void InfoSaver::initializeUser(size_t user_id)
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
