#pragma once
#include "../../../Infrastructure/UserRegistration/UserRegistrationRequest.h"
#include "../../../Infrastructure/UserRegistration/UserRegistrationResponse.h"

class UserRegistrationContext
{
public:
    static UserRegistrationResponse RegisterUser(const UserRegistrationRequest &request);

private:
    static bool UserExists(const User &user);
    static void ApplyChangesUser(User &user);
    static void ApplyChangesCredentials(const Credentials &userCredentials);
};