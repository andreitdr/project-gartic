#include "JoinLobbyResponse.h"

JoinLobbyResponse::JoinLobbyResponse()
{
    m_successState = true;
}

JoinLobbyResponse::JoinLobbyResponse(const std::string& message)
{
    m_successState = false;
    AppendMessage(message);
}
