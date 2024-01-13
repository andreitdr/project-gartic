#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/GetDrawingRequest.h"
#include "../../../Infrastructure/GameManager/GetDrawingResponse.h"

class GetDrawingContext final : public BaseContext<GetDrawingRequest,GetDrawingResponse>
{
public:
    GetDrawingResponse HandleRequest(const GetDrawingRequest& request) override;

private:
    GetDrawingResponse ApplyChanges(const GetDrawingRequest& request) override;
    
};
