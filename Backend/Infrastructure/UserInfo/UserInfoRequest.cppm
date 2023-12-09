export module UserInfoRequest;

export class UserInfoRequest
{
public:
    UserInfoRequest(const int userID);
    int GetUserID() const;

private:
    int m_userID;
};

UserInfoRequest::UserInfoRequest(const int userID) : m_userID{userID}
{
}

int UserInfoRequest::GetUserID() const
{
    return m_userID;
}
