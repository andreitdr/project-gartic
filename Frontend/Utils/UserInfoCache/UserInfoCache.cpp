#include "UserInfoCache.h"

UserInfoCache::UserInfoCache()
{
}

UserInfoCache& UserInfoCache::getInstance()
{
    static UserInfoCache instance;
    return instance;
}

UserInfo UserInfoCache::getUserInfo(int userId)
{
    auto it = cache.find(userId);
    if (it != cache.end()) {
        return it->second;
    }
    UserInfo userInfo = UserInfo::GetUserInfoFromServer(userId);
    cache[userId] = userInfo;
    return userInfo;
}
