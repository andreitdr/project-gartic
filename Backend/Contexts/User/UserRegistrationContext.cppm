#include "../../SqlDatabase/SqlDatabase.h"
export module UserRegistrationContext;
import<string>;

export import UserRegistrationRequest;
export import UserRegisterResponse;
export import User;

export class UserRegistrationContext
{
public:
    static UserRegisterResponse RegisterUser(const UserRegistrationRequest& request);

private:
    static bool UserExists(const UserStructModel& user);
    static UserStructModel ApplyChanges(UserStructModel user);
};

UserRegisterResponse UserRegistrationContext::RegisterUser(const UserRegistrationRequest& request)
{
    auto user = request.GetObject();
    
    if(UserExists(user))
    {
        return UserRegisterResponse("The user already exists", false);
    }

    UserRegisterResponse response = UserRegisterResponse("Success", true);
    user = ApplyChanges(user);
    response.SetUser(user);
    
    return response;
}

bool UserRegistrationContext::UserExists(const UserStructModel& user)
{
    return SqlDatabase::Exists(user);
}

UserStructModel UserRegistrationContext::ApplyChanges(UserStructModel user)
{
    int id = SqlDatabase::Insert(user);
    user.m_user_id = id;
    return user;
}

