export module UserRegistrationContext;
import <string>;

#include "../../SqlDatabase/SqlDatabase.h"

export import UserRegistrationRequest;
export import UserRegisterResponse;
export import User;

export class UserRegistrationContext
{
public:
    static UserRegistrationResponse RegisterUser(const UserRegistrationRequest& request);

private:
    static bool UserExists(const UserStructModel& user);
    static void ApplyChangesUser(UserStructModel& user);
    static void ApplyChangesCredentials(const Credentials& userCredentials);
};

UserRegistrationResponse UserRegistrationContext::RegisterUser(const UserRegistrationRequest& request)
{
    auto user = request.GetUser(); // user
    auto credentials = request.GetCredentials(); // credentials
    
    if(UserExists(user))
    {
        return UserRegistrationResponse("The user already exists", false);
    }

    UserRegistrationResponse response = UserRegistrationResponse("Success", true);
    ApplyChangesUser(user);
    ApplyChangesCredentials(credentials);
    response.SetUser(user);
    
    return response;
}

bool UserRegistrationContext::UserExists(const UserStructModel& user)
{
    return SqlDatabase::Exists(user);
}

void UserRegistrationContext::ApplyChangesUser(UserStructModel& user)
{
    int id = SqlDatabase::Insert(user);
    user.m_user_id = id;
}

void UserRegistrationContext::ApplyChangesCredentials(const Credentials& userCredentials)
{
    SqlDatabase::Insert(userCredentials);
}

