#include "UserInfoCache.h"
#include "../../API/Contexts/Contexts.h"

UserInfoCache::UserInfoCache()
{
}

UserInfo UserInfoCache::getUserInfoFromServer(int userId)
{
    Contexts contexts;
    UserInfo user;
    contexts.getUserInfo(userId, [&user](bool success, const std::string message, const UserInfo& userInfo)
        {
            if(success)
                user = userInfo;
            else
                user=UserInfo();
        });
    return user;
}

UserInfoCache& UserInfoCache::getInstance()
{
    static UserInfoCache instance;
    return instance;
}

UserInfo UserInfoCache::getUserInfo(int userId)
{
    std::lock_guard<std::mutex> lock(m_UserInfoCacheMutex);
    auto it = m_cache.find(userId);
    if (it != m_cache.end()) {
        return it->second;
    }
    UserInfo userInfo = getUserInfoFromServer(userId);
    m_cache[userId] = userInfo;
    return userInfo;
}
