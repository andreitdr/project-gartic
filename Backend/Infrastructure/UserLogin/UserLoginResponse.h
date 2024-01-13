#pragma once
#include <string>

#include "../../DataTypes/User/User.h"
#include "../../Infrastructure/BaseResponse.h"

class UserLoginResponse : public BaseResponse
{
public:
    UserLoginResponse(const std::string& message, bool state);
    UserLoginResponse(bool state);
    UserLoginResponse(const User& user);

    User GetUser() const;

private:
    User m_user;
};
