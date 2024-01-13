#pragma once

#include "../../BaseContext.h"
#include "../../../Infrastructure/UserLogin/UserLoginRequest.h"
#include "../../../Infrastructure/UserLogin/UserLoginResponse.h"

class UserLoginContext : BaseContext<UserLoginRequest, UserLoginResponse>
{
public:
    UserLoginResponse HandleRequest(const UserLoginRequest& request) override;
    UserLoginResponse ApplyChanges(const UserLoginRequest& request) override;

private:
    UserLoginResponse ValidateData(const UserLoginRequest& request);
};