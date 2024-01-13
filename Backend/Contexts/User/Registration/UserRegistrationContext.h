#pragma once
#include "../../../Infrastructure/UserRegistration/UserRegistrationRequest.h"
#include "../../../Infrastructure/UserRegistration/UserRegistrationResponse.h"
#include "../../BaseContext.h"

class UserRegistrationContext : BaseContext<UserRegistrationRequest, UserRegistrationResponse>
{
public:
    UserRegistrationResponse HandleRequest(const UserRegistrationRequest &request) override;
    UserRegistrationResponse ApplyChanges(const UserRegistrationRequest &request) override;

private:
     UserRegistrationResponse ValidateData(const User &user);
     void ApplyChangesUser(User &user);
     void ApplyChangesCredentials(const Credentials &userCredentials);
};