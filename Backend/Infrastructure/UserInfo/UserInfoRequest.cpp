#include "UserInfoRequest.h"

UserInfoRequest::UserInfoRequest(const int userID) : m_userID{userID}
{
}

int UserInfoRequest::GetUserID() const
{
    return m_userID;
}
