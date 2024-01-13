#include "BaseResponse.h"

BaseResponse::BaseResponse() : m_successState{true}
{
    m_messages     = {};
}

BaseResponse::BaseResponse(bool state) : m_successState{state}
{
}

void BaseResponse::AppendMessage(const std::string& message)
{
    m_messages.emplace_back(message);
}

BaseResponse::operator bool() const
{
    return m_successState;
}
