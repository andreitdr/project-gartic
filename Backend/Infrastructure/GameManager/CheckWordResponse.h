#pragma once
#include "../BaseResponse.h"
#include <string>

class CheckWordResponse : public BaseResponse
{
public:
    CheckWordResponse(const std::string& message);
    CheckWordResponse(const std::string& message, bool success);
    CheckWordResponse(bool success);
};
