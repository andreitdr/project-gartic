#pragma once
#include "User.h"
#include "Credentials.h"
class UserLogin
{
public:
	UserLogin(const User& user, const Credentials& credentials);

private:
	User m_user;
	Credentials m_credentials;
};

