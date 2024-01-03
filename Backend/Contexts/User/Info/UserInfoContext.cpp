#include "UserInfoContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"

UserInfoResponse UserInfoContext::HandleRequest(const UserInfoRequest &request)
{
    const User user = GetUserFromDatabase(request.GetUserID());
    UserInfoResponse response(user);
    return response;
}

User UserInfoContext::GetUserFromDatabase(int userID)
{
    std::optional<User> user = SqlDatabase::Get<User>(userID);
    if (!user.has_value())
        throw std::runtime_error("User does not exist");

    return user.value();
}

UserInfoResponse UserInfoContext::ApplyChanges(const UserInfoRequest &request)
{
    return UserInfoResponse(User());
}