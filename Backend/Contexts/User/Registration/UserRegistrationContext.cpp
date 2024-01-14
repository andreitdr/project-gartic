#include "UserRegistrationContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"

UserRegistrationResponse UserRegistrationContext::HandleRequest(const UserRegistrationRequest& request)
{
    auto user = request.GetUser();               // user
    auto credentials = request.GetCredentials(); // credentials
    
    auto response = ValidateData(user);
    if (!ValidateData(user))
        return response;

    response = ApplyChanges(request);
    
    return response;
}

UserRegistrationResponse UserRegistrationContext::ApplyChanges(const UserRegistrationRequest& request)
{
    auto user              = request.GetUser();        // user
    const auto credentials = request.GetCredentials(); // credentials

    ApplyChangesUser(user);
    ApplyChangesCredentials(credentials);

    return UserRegistrationResponse(user);
}

UserRegistrationResponse UserRegistrationContext::ValidateData(const User& user)
{
    if(SqlDatabase::GetInstance().Exists<User>(WHERE(User::m_username, user.m_username)))
        return UserRegistrationResponse("The user already exists", false);

    return UserRegistrationResponse(true);
}


void UserRegistrationContext::ApplyChangesUser(User &user)
{
    int id = SqlDatabase::GetInstance().Insert(user);
    user.m_user_id = id;
}

void UserRegistrationContext::ApplyChangesCredentials(const Credentials &userCredentials)
{
    SqlDatabase::GetInstance().Insert(userCredentials);
}
