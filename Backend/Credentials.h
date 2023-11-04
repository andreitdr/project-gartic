#pragma once
#include <string>
class Credentials
{
private:
	std::string m_username;
	std::string m_nonHashedPassword;

public:
	Credentials(const std::string& username, const std::string& nonHashedPassword);
	std::string hashString(const std::string& stringToBeHashed);
	const std::string getNonHashedPassword() const;

	const std::string getUsername() const;
	bool verifyPassword(const std::string& givenPassword);
};

