#include "UserRegister.h"

UserRegister::UserRegister(const User& user, const Credentials& credentials) : 
	m_user(user), m_credentials(credentials) {}

bool UserRegister::registerUser()
{
	if (userExists(m_user.getUsername()))
	{
		return false;
	}
	User newUser(m_user.getSurname(), m_user.getGivenName(), m_user.getUsername());

	std::string hashedPassword = m_credentials.hashString(m_credentials.getNonHashedPassword());
	Credentials newCredentialsForUser(newUser.getUsername(), hashedPassword);

	//saved the data in memory, until database integration
	std::vector<User> users;
	std::vector<Credentials> credentials;
	users.push_back(newUser);
	credentials.push_back(newCredentialsForUser);

	return true;
}

bool UserRegister::userExists(const std::string& username)
{
	std::vector<std::string> registeredUsernames;
	for (const std::string& registeredUsername : registeredUsernames)
	{
		if (username == registeredUsername)
		{
			return true; 
		}
	}
	return false;
}
