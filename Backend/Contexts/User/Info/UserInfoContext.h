#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/UserInfo/UserInfoRequest.h"
#include "../../../Infrastructure/UserInfo/UserInfoResponse.h"

class UserInfoContext final : public BaseContext<UserInfoRequest, UserInfoResponse> {
    public:
       UserInfoResponse HandleRequest(const UserInfoRequest& request);

    private:
       UserInfoResponse ApplyChanges(const UserInfoRequest& request);
       User GetUserFromDatabase(int userId);
};
