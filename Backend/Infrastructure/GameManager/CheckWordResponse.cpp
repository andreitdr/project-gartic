#include "CheckWordResponse.h"

CheckWordResponse::CheckWordResponse(const std::string& message)
    : BaseResponse{false}
{
    AppendMessage(message);
}

CheckWordResponse::CheckWordResponse(const std::string& message, bool success)
    : BaseResponse{success}
{
    AppendMessage(message);
}

CheckWordResponse::CheckWordResponse(bool success)
    : BaseResponse{success}
{
}