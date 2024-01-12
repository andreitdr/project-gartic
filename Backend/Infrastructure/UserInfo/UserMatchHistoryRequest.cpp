#include "UserMatchHistoryRequest.h"

UserMatchHistoryRequest::UserMatchHistoryRequest(int userId) : m_userId{userId}
{
}

int UserMatchHistoryRequest::GetUserId() const
{
    return m_userId;
}
