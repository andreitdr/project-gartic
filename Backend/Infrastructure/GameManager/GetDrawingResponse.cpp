#include "GetDrawingResponse.h"

GetDrawingResponse::GetDrawingResponse(const std::string& drawing, bool success)
	: BaseResponse{success}, m_drawing{drawing}
{
}

GetDrawingResponse::GetDrawingResponse(const std::string& message) : BaseResponse{false}
{
    AppendMessage(message);
}

std::string GetDrawingResponse::GetDrawing() const
{
    return m_drawing;
}
