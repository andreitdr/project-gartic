#pragma once
import User;
#include "Credentials.h"
#include <vector>
#include <string>
class UserRegister
{
public:
	UserRegister(const User& user, const Credentials& credentials);

	bool registerUser();

private:
	User m_user;
	Credentials m_credentials;
	bool userExists(const std::string& username);
};

