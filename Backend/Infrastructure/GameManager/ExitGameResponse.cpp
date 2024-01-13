#include "ExitGameResponse.h"

ExitGameResponse::ExitGameResponse():BaseResponse{true}
{
    
}

ExitGameResponse::ExitGameResponse(const std::string& message):BaseResponse{false}
{
    AppendMessage(message);
}
