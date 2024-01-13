#pragma once
#include "../BaseResponse.h"

class GetChatMessagesResponse : public BaseResponse
{
public:
    GetChatMessagesResponse(const std::vector<std::string>& messages);
    GetChatMessagesResponse(const std::string& message);
    GetChatMessagesResponse(const std::string& message, bool state);
    GetChatMessagesResponse(bool state);
    
    std::vector<std::string> GetMessages() const;
    
private:
    std::vector<std::string> m_chatMessages;
};
