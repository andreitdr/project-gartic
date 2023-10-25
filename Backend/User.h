#pragma once
#include <string>
class User
{
public:
	const std::string getSurname() const;
	const std::string getGivenName() const;

private:
	std::string m_surname;
	std::string m_givenName;
	std::string m_username;


	User(const std::string& surname, const std::string& givenName, const std::string& username);
};

