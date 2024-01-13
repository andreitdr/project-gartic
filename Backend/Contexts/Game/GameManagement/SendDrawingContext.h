#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/SendDrawingRequest.h"
#include "../../../Infrastructure/GameManager/SendDrawingResponse.h"

class SendDrawingContext final : BaseContext<SendDrawingRequest,SendDrawingResponse>
{
public:
    SendDrawingResponse HandleRequest(const SendDrawingRequest& request) override;
private:
    SendDrawingResponse ApplyChanges(const SendDrawingRequest& request) override;
    
};
