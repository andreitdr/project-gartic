#include "SendDrawingResponse.h"

SendDrawingResponse::SendDrawingResponse() : BaseResponse{true}
{
}

SendDrawingResponse::SendDrawingResponse(const std::string message): BaseResponse{false}
{
    AppendMessage(message);
}
