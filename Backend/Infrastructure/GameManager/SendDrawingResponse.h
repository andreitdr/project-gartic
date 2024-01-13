#pragma once
#include "../BaseResponse.h"

class SendDrawingResponse : public BaseResponse
{
public:
    SendDrawingResponse();
    SendDrawingResponse(const std::string message);
    
};
