export module UserLoginGateway;

export import UserLoginRequest;
export import UserLoginResponse;
export import sqlmodule;
import <string>;
export class UserLoginGateway
{
public:
    UserLoginResponse Login(UserLoginRequest& request);
private:
    bool UserExists(const credentials& user);
};

UserLoginResponse UserLoginGateway::Login(UserLoginRequest& request)
{
    UserLoginResponse response = UserLoginResponse();
    const credentials object = request.GetObject();

    if(!UserExists(object))
    {
        return UserLoginResponse("The user could not be found !", false);
    }
    auto database = SqlDatabase::GetDatabase();

    std::string sql = "SELECT * FROM Credentials where Username=@username"; 

    response.SetCredentials(database.GetData<credentials>(sql));
    response.SetResponseState(true);
    return response;
}

bool UserLoginGateway::UserExists(const credentials& user)
{
    auto database = SqlDatabase::GetDatabase();
    if(database.RecordExists(user)) return true;
    return false;
}




