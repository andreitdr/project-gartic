export module UserRegistrationGateway;
import<string>;

export import UserRegistrationRequest;
export import UserRegisterResponse;

export import User;
export import sqlmodule;

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
    auto user = request.GetObject();
    
    if(UserExists(user))
    {
        return UserRegisterResponse("The user already exists", false);
    }

    UserRegisterResponse response;
    user = ApplyChanges(user);
    response.SetUser(user);
    response.SetResponseState(true);

    return response;
    
}

bool UserRegistrationGateway::UserExists(const UserStructModel& user)
{
    return SqlDatabase::GetDatabase().RecordExists<UserStructModel>(user);
}

UserStructModel UserRegistrationGateway::ApplyChanges(UserStructModel user)
{
    auto database = SqlDatabase::GetDatabase();
    int id = database.Insert(user);

    user.m_user_id = id;

    return user;
}

