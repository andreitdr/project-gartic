#include "UserRegister.h"
import infosaver;
UserRegister::UserRegister(const User& user, const Credentials& credentials) : 
	m_user(user), m_credentials(credentials) {}

bool UserRegister::registerUser()
{
	if (InfoSaver::GetUser(m_user.m_user_id)!=NULL)
		return 
	User newUser(m_user.getSurname(), m_user.getGivenName(), m_user.getUsername());

	std::string hashedPassword = m_credentials.hashString(m_credentials.getNonHashedPassword());
	Credentials newCredentialsForUser(newUser.getUsername(), hashedPassword);

	//saved the data in file, until database integration
	std::vector<Credentials> credentials;
	InfoSaver::InitializeUser(newUser); 
	credentials.push_back(newCredentialsForUser);

	return true;
}


