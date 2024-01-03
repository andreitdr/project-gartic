#include "BaseResponse.h"

BaseResponse::BaseResponse()
{
    m_successState = false;
    m_messages     = {};
}

void BaseResponse::AppendMessage(const std::string& message)
{
    m_messages.emplace_back(message);
}

BaseResponse::operator bool() const
{
    return m_successState;
}
