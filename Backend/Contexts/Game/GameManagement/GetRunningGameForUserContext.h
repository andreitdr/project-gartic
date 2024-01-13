#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/GetRunningGameForUserRequest.h"
#include "../../../Infrastructure/GameManager/GetRunningGameForUserResponse.h"

class GetRunningGameForUserContext final : public BaseContext<GetRunningGameForUserRequest,GetRunningGameForUserResponse>
{
public:
    GetRunningGameForUserResponse HandleRequest(const GetRunningGameForUserRequest& request) override;

private:
    GetRunningGameForUserResponse ApplyChanges(const GetRunningGameForUserRequest& request) override;
};
