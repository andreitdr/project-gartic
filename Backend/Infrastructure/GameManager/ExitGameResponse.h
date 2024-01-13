#pragma once
#include "../BaseResponse.h"

class ExitGameResponse : public BaseResponse
{
public:
    ExitGameResponse();
    ExitGameResponse(const std::string& message);
    
};
