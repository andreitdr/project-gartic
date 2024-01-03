#include "UserRegistrationContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"

UserRegistrationResponse UserRegistrationContext::RegisterUser(const UserRegistrationRequest &request)
{
    auto user = request.GetUser();               // user
    auto credentials = request.GetCredentials(); // credentials

    if (UserExists(user))
    {
        auto response = UserRegistrationResponse("The user already exists", false);
        response.SetUser(user);

        return response;
    }

    auto response = UserRegistrationResponse("Success", true);
    ApplyChangesUser(user);
    ApplyChangesCredentials(credentials);
    response.SetUser(user);

    return response;
}

bool UserRegistrationContext::UserExists(const User &user)
{
    return SqlDatabase::ExistsModel(user);
}

void UserRegistrationContext::ApplyChangesUser(User &user)
{
    int id = SqlDatabase::Insert(user);
    user.m_user_id = id;
}

void UserRegistrationContext::ApplyChangesCredentials(const Credentials &userCredentials)
{
    SqlDatabase::Insert(userCredentials);
}
