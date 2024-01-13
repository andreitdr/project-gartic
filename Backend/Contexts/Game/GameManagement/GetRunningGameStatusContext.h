#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/GetRunningGameStatusRequest.h"
#include "../../../Infrastructure/GameManager/GetRunningGameStatusResponse.h"

class GetRunningGameStatusContext final : public BaseContext<GetRunningGameStatusRequest, GetRunningGameStatusResponse>
{
public:
    GetRunningGameStatusResponse HandleRequest(const GetRunningGameStatusRequest& request) override;

private:
    GetRunningGameStatusResponse ApplyChanges(const GetRunningGameStatusRequest& request) override;
    static GetRunningGameStatusResponse ValidateData(const GetRunningGameStatusRequest& request);
};
