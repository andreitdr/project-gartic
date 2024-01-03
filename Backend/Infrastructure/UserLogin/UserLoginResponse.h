#pragma once
#include <string>

#include "../../Infrastructure/BaseResponse.h"

class UserLoginResponse : public BaseResponse
{
public:
    UserLoginResponse(const std::string& message, bool state);
    UserLoginResponse(bool state);
};
