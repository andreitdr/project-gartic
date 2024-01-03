#pragma once

class UserInfoRequest
{
public:
    UserInfoRequest(const int userID);
    int GetUserID() const;

private:
    int m_userID;
};
