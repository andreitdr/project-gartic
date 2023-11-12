export module UserRegistrationGateway;
import <string>;

import UserRegistrationRequest;
import UserRegisterResponse;

import User;
import sqlmodule;

export class UserRegistrationGateway
{
public:
    UserRegisterResponse RegisterUser(const UserRegistrationRequest& request);

private:
    bool UserExists(const UserStructModel& user);
    UserStructModel ApplyChanges(UserStructModel user);
    
};

UserRegisterResponse UserRegistrationGateway::RegisterUser(const UserRegistrationRequest& request)
{
    const auto user = request.GetObject();

    UserStructModel struct_model;
    struct_model.m_surname = user.getSurname();
    struct_model.m_user_id = -1; // temp ID
    struct_model.m_username = user.getUsername();
    struct_model.m_givenName = user.getGivenName();
    
    if(UserExists(struct_model))
    {
        return UserRegisterResponse("The user already exists", false);
    }

    UserRegisterResponse response;
    response.SetUser(ApplyChanges(struct_model));
    response.SetResponseState(true);

    return response;
    
}

bool UserRegistrationGateway::UserExists(const UserStructModel& user)
{
    return SqlDatabase::GetDatabase().RecordExists<UserStructModel>(user);
}

UserStructModel UserRegistrationGateway::ApplyChanges(const UserStructModel& user)
{
    auto database = SqlDatabase::GetDatabase();
    int id = database.Insert(user);

    user.m_user_id = id;

    return user;
}

