#include "JoinRandomLobbyResponse.h"

JoinRandomLobbyResponse::JoinRandomLobbyResponse()
{
    m_successState = true;
}

JoinRandomLobbyResponse::JoinRandomLobbyResponse(const std::string &message)
{
    m_successState = false;
    AppendMessage(message);
}