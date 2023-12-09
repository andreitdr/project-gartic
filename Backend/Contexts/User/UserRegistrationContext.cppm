export module UserRegistrationContext;

#include "../../SqlDatabase/SqlDatabase.h"
import <string>;

export import UserRegistrationRequest;
export import UserRegisterResponse;

export class UserRegistrationContext
{
public:
    static UserRegistrationResponse RegisterUser(const UserRegistrationRequest& request);

private:
    static bool UserExists(const User& user);
    static void ApplyChangesUser(User& user);
    static void ApplyChangesCredentials(const Credentials& userCredentials);
};

UserRegistrationResponse UserRegistrationContext::RegisterUser(const UserRegistrationRequest& request)
{
    auto user = request.GetUser(); // user
    auto credentials = request.GetCredentials(); // credentials
    
    if(UserExists(user))
    {
        UserRegistrationResponse response = UserRegistrationResponse("The user already exists", false);
        response.SetUser(user);
        
        return response;
    }

    UserRegistrationResponse response = UserRegistrationResponse("Success", true);
    ApplyChangesUser(user);
    ApplyChangesCredentials(credentials);
    response.SetUser(user);
    
    return response;
}

bool UserRegistrationContext::UserExists(const User& user)
{
    return SqlDatabase::ExistsModel(user);
}

void UserRegistrationContext::ApplyChangesUser(User& user)
{
    int id = SqlDatabase::Insert(user);
    user.m_user_id = id;
}

void UserRegistrationContext::ApplyChangesCredentials(const Credentials& userCredentials)
{
    SqlDatabase::Insert(userCredentials);
}

