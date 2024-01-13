#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/GetChatMessagesRequest.h"
#include "../../../Infrastructure/GameManager/GetChatMessagesResponse.h"

class GetChatMessagesContext:public BaseContext<GetChatMessagesRequest, GetChatMessagesResponse>
{
public:
    GetChatMessagesResponse HandleRequest(const GetChatMessagesRequest& request) override;

private:
    GetChatMessagesResponse ApplyChanges(const GetChatMessagesRequest& request) override;
    GetChatMessagesResponse ValidateData(const GetChatMessagesRequest& request) ;
    
};
