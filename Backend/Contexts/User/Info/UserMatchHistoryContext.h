#pragma once
#include "../../BaseContext.h"

#include "../../../Infrastructure/UserInfo/UserMatchHistoryRequest.h"
#include "../../../Infrastructure/UserInfo/UserMatchHistoryResponse.h"


class UserMatchHistoryContext final : public BaseContext<UserMatchHistoryRequest, UserMatchHistoryResponse>
{
public:
    UserMatchHistoryResponse HandleRequest(const UserMatchHistoryRequest& request) override;

private:
    UserMatchHistoryResponse ApplyChanges(const UserMatchHistoryRequest& request) override;
    UserMatchHistoryResponse ValidateData(const UserMatchHistoryRequest& request);
};
