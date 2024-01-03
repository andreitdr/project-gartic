#include "StartGameRequest.h"

StartGameRequest::StartGameRequest(const std::vector<int>& userIds) : m_userIds{userIds}
{
}

std::vector<int> StartGameRequest::GetUsers() const
{
    return m_userIds;
}
