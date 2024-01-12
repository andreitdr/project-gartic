#pragma once

class UserMatchHistoryRequest
{
public:
    UserMatchHistoryRequest(int userId);
    int GetUserId() const;
    
private:
    int m_userId;
};
