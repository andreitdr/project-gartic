#pragma once
import UserInfoContext;
#include <crow.h>
#include "../../Utils/JsonConvertor.h"


inline WJSON GetUserInfo(const crow::json::rvalue& request)
{
    const int userID = request["userID"].i();
    const UserInfoRequest userInfoRequest = UserInfoRequest(userID);
    const UserInfoResponse userInfoResponse = UserInfoContext::GetUserInfo(userInfoRequest);

    WJSON JResponse = JsonConvertor::ConvertBaseResponse(userInfoResponse);
    const User user = userInfoResponse.GetUser();
    JResponse["user"]["id"] = user.m_user_id;
    JResponse["user"]["surname"] = user.m_surname;
    JResponse["user"]["givenName"] = user.m_givenName;
    JResponse["user"]["username"] = user.m_username;

    return JResponse;
}
