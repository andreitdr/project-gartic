#pragma once
#include "../UserInfo/UserInfo.h"
#include <unordered_map>

class UserInfoCache {
public:
    static UserInfoCache& getInstance();

    UserInfo getUserInfo(int userId);

private:
    UserInfoCache();
    std::unordered_map<int, UserInfo> cache;

    UserInfoCache(const UserInfoCache&) = delete;
    void operator=(const UserInfoCache&) = delete;
};
