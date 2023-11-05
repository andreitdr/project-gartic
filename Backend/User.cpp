#include "User.h"
#include <map>
const std::string User::getSurname() const
{
	return m_surname;
}

const std::string User::getGivenName() const
{
	return m_givenName;
}

const std::string User::getUsername() const
{
	return m_username;
}

size_t User::GenerateUserId(const std::string& username)
{
	std::hash<std::string> hasher;
	return hasher(username);
}

User::User(const std::string& surname, const std::string& givenName, const std::string& username)
	: m_surname(surname), m_givenName(givenName), m_username(username), m_user_id(GenerateUserId(username))
{
	// some other implementations
}
