#include "GetChatMessagesResponse.h"

GetChatMessagesResponse::GetChatMessagesResponse(const std::vector<std::string>& messages) : BaseResponse{true}, m_chatMessages{messages}
{
}

GetChatMessagesResponse::GetChatMessagesResponse(const std::string& message) : BaseResponse{false}
{
    AppendMessage(message);
}

GetChatMessagesResponse::GetChatMessagesResponse(const std::string& message, bool state) : BaseResponse{state}
{
    AppendMessage(message);
}

GetChatMessagesResponse::GetChatMessagesResponse(bool state) : BaseResponse{state}
{
}

std::vector<std::string> GetChatMessagesResponse::GetMessages() const
{
    return m_chatMessages;
}


