export module UserInfoResponse;

export import BaseResponse;
export import User;

export class UserInfoResponse : public BaseResponse
{
public:
    UserInfoResponse(const User& user);
    User GetUser() const;
private:
    User m_user;
};

UserInfoResponse::UserInfoResponse(const User& user) : m_user{user}
{
    m_successState = true;
}

User UserInfoResponse::GetUser() const
{
    return m_user;
}
