#pragma once
#include<string>

#include "../BaseResponse.h"

class GetDrawingResponse : public BaseResponse
{
public:
    GetDrawingResponse(const std::string& drawing, bool success);
    GetDrawingResponse(const std::string& message);
    std::string GetDrawing() const;

private:
    std::string m_drawing;
    
};
