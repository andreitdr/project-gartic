#pragma once
#include <string>

#include "../../Infrastructure/BaseResponse.h"
#include "../../DataTypes/User/User.h"

class UserRegistrationResponse : public BaseResponse
{
public:
    UserRegistrationResponse(const std::string& message, bool state);
    UserRegistrationResponse(bool state);
    UserRegistrationResponse(const User& user);

    void SetUser(const User& user);
    User GetUser() const;

private:
    User m_user;
};
