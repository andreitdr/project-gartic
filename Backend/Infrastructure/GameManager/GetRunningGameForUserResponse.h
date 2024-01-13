#pragma once

#include <string>

#include "../BaseResponse.h"

class GetRunningGameForUserResponse : public BaseResponse
{
public:
    GetRunningGameForUserResponse(int gameId);
    GetRunningGameForUserResponse(const std::string& message);
    int GetGameId() const;
    
private:
    int m_gameId;
    
};
