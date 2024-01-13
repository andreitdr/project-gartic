#include "UserLoginContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"


UserLoginResponse UserLoginContext::HandleRequest(const UserLoginRequest& request)
{
    UserLoginResponse response = ValidateData(request);
    if (!response)
        return response;

    return ApplyChanges(request);
}

UserLoginResponse UserLoginContext::ApplyChanges(const UserLoginRequest& request)
{
    const User user = SqlDatabase::GetInstance().Get<User>(WHERE(User::m_username, request.GetCredentials().m_username));
    return UserLoginResponse(user);
}


UserLoginResponse UserLoginContext::ValidateData(const UserLoginRequest& request)
{
    Credentials credentials = request.GetCredentials();
    if (!SqlDatabase::GetInstance().ExistsModel(credentials))
        return UserLoginResponse("Inexistent user", false);

    using namespace sqlite_orm;
    auto whereCondition = where(c(&Credentials::m_username) == credentials.m_username and c(&Credentials::m_hashedPassword) == credentials.m_hashedPassword);
    if (!SqlDatabase::GetInstance().Exists<Credentials>(whereCondition))
        return UserLoginResponse("Incorrect password", false);

    return UserLoginResponse(true);
}
