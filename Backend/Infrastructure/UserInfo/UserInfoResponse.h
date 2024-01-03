#pragma once

#include "../BaseResponse.h"
#include "../../DataTypes/User/User.h"

class UserInfoResponse : public BaseResponse
{
public:
    UserInfoResponse(const User& user);
    User GetUser() const;

private:
    User m_user;
};
