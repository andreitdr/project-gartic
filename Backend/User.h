#pragma once
#include <string>
class User
{
public:
	friend class UserRegister;
	const std::string getSurname() const;
	const std::string getGivenName() const;
	const std::string getUsername() const;

private:
	std::string m_surname;
	std::string m_givenName;
	std::string m_username;
	size_t m_user_id;

	size_t GenerateUserId(const std::string& username);
	User(const std::string& surname, const std::string& givenName, const std::string& username);
};

