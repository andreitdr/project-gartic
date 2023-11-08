import infosaver;
import <format>;
import <fstream>;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::string InfoSaver::GetFile(const std::string& file_prefix, const std::string& file_suffix)
{
	std::string file = file_prefix + file_suffix;
	return file;
}
void InfoSaver::SetPoints(const size_t user_id, int point_number)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(GetFile(user_as_string));
	users = json::parse(i);
	i.close();
	std::ofstream f(GetFile(user_as_string));
	users["Points"] = point_number;
	f << std::setw(4) << users << std::endl;
	f.close();
}


int InfoSaver::GetPoints(const size_t user_id)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(GetFile(user_as_string));
	users = json::parse(i);
	i.close();
	return users["Points"].template get<int>();
}
void InfoSaver::SetUsername(const size_t user_id,const std::string& username)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(GetFile(user_as_string));
	users = json::parse(i);
	i.close();
	std::ofstream f(GetFile(user_as_string));
	users["Username"] = username;
	f << std::setw(4) << users << std::endl;
	f.close();
}

std::string InfoSaver::GetUsername(const size_t user_id)
{
	json users;
	std::string user_as_string = std::format("{0}", user_id);
	std::ifstream i(GetFile(user_as_string));
	users = json::parse(i);
	i.close();
	return users["Username"].template get<std::string>();
}

void InfoSaver::InitializeUser(const User& user)
{
	json users;
	std::string user_as_string = std::format("{0}", user.m_user_id);
	std::ofstream o(GetFile(user_as_string));
	users["Username"] = user.m_username;
	users["Points"] = 0;
	o << std::setw(4) << users << std::endl;
	o.close();
}
