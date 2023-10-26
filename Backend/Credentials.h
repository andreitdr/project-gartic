#pragma once
#include <string>
class Credentials
{
private:
	std::string m_username;
	std::size_t m_hashedPassword;

public:
	Credentials(const std::string& username, const std::string& nonHashedPassword);
	static std::size_t hashString(const std::string& stringToBeHashed);
};

