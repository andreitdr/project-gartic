#pragma once

class GetRunningGameForUserRequest
{
public:
    GetRunningGameForUserRequest(int userId);
    int GetUserId() const;

private:
    int m_userId;
    
};
