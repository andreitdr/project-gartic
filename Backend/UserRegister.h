#pragma once
#include "User.h"
#include "Credentials.h"
#include <vector>
#include <string>
class UserRegister
{
public:
	UserRegister(User& user, Credentials& credentials);

	bool registerUser();

private:
	User m_user;
	Credentials m_credentials;
	bool userExists(const std::string& username);
};

