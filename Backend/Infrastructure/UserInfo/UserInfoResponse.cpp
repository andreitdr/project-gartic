#include "UserInfoResponse.h"

UserInfoResponse::UserInfoResponse(const User& user) : m_user{user}
{
    m_successState = true;
}

User UserInfoResponse::GetUser() const
{
    return m_user;
}
