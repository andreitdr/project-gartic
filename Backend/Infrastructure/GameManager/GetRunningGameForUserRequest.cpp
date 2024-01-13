#include "GetRunningGameForUserRequest.h"

GetRunningGameForUserRequest::GetRunningGameForUserRequest(int userId): m_userId{userId}
{
}

int GetRunningGameForUserRequest::GetUserId() const
{
    return m_userId;
}
