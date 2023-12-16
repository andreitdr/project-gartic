export module UserInfoContext;

#include "../../SqlDatabase/SqlDatabase.h"


export import User;
export import UserInfoRequest;
export import UserInfoResponse;

export class UserInfoContext
{
public:
    static UserInfoResponse GetUserInfo(const UserInfoRequest& request);
    
private:
    static User GetUserFromDatabase(int userID);
};

UserInfoResponse UserInfoContext::GetUserInfo(const UserInfoRequest& request)
{
    const User user = GetUserFromDatabase(request.GetUserID());
    UserInfoResponse response(user);
    return response;
}

User UserInfoContext::GetUserFromDatabase(const int userID)
{
    return SqlDatabase::Get<User>(userID);
}
