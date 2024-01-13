#include "GetRunningGameForUserResponse.h"

GetRunningGameForUserResponse::GetRunningGameForUserResponse(int gameId):BaseResponse(true),m_gameId(gameId)
{
}

GetRunningGameForUserResponse::GetRunningGameForUserResponse(const std::string& message):BaseResponse(false)
{
    AppendMessage(message);
}

int GetRunningGameForUserResponse::GetGameId() const
{
    return m_gameId;
}
