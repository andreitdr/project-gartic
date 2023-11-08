#pragma once
#include "User.h"
#include "Credentials.h"
#include <string>

class UserLogin
{
public:
	UserLogin(const User& user, const Credentials& credentials);
	bool login(const std::string& givenPassword);

private:
	User m_user;
	Credentials m_credentials;
};

