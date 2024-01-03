#pragma once
#include <string>

#include "../../../Infrastructure/BaseResponse.h"

class LeaveLobbyResponse : public BaseResponse
{
public:
    LeaveLobbyResponse();
    LeaveLobbyResponse(const std::string& message);
};
