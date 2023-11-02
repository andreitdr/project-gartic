#include "UserLogin.h"

UserLogin::UserLogin(const User& user, const Credentials& credentials) :
	m_user(user), m_credentials(credentials) 
{}

bool UserLogin::login(const std::string& givenPassword)
{
	if (m_user.getUsername() != m_credentials.getUsername())
	{
		return false;
	}

	if (m_credentials.verifyPassword(givenPassword))
	{
		return true;
	}
	
	return false;
}

