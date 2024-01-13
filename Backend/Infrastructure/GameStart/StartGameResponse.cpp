#include "StartGameResponse.h"

StartGameResponse::StartGameResponse(int gameID) : BaseResponse(true), m_gameID{gameID}
{
}

StartGameResponse::StartGameResponse(const std::string& message) : BaseResponse(false)
{
    AppendMessage(message);
}


int StartGameResponse::GetGameID() const
{
    return m_gameID;
}

