#include "LeaveLobbyResponse.h"

LeaveLobbyResponse::LeaveLobbyResponse()
{
    m_successState = true;
}

LeaveLobbyResponse::LeaveLobbyResponse(const std::string& message)
{
    m_successState = false;
    AppendMessage(message);
}
