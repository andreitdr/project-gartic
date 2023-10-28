#include "User.h"

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

User::User(const std::string& surname, const std::string& givenName, const std::string& username)
	: m_surname(surname), m_givenName(givenName), m_username(username)
{
	// some other implementations
}
