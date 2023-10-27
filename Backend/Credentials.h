#pragma once
#include <string>
class Credentials
{
private:
	std::string m_username;
	std::string m_hashedPassword;

public:
	Credentials(const std::string& username, const std::string& nonHashedPassword);
	std::string hashString(const std::string& stringToBeHashed);
};

