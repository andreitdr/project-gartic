#pragma once
#include "../UserInfo/UserInfo.h"
#include <unordered_map>
#include <mutex>

class UserInfoCache {
public:
    static UserInfoCache& getInstance();

    UserInfo getUserInfo(int userId);

private:
    UserInfoCache();
    UserInfo getUserInfoFromServer(int userId);
    std::unordered_map<int, UserInfo> m_cache;
    std::mutex m_UserInfoCacheMutex;

    UserInfoCache(const UserInfoCache&) = delete;
    void operator=(const UserInfoCache&) = delete;
};
