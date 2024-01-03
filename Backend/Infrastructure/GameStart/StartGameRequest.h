#pragma once
#include <vector>

class StartGameRequest
{
public:
    StartGameRequest(const std::vector<int>& userIds);
    std::vector<int> GetUsers() const;

private:
    std::vector<int> m_userIds;
};
