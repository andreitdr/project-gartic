#include "UpdateLobbyResponse.h"


UpdateLobbyResponse::UpdateLobbyResponse()
{
    m_successState = true;
}

UpdateLobbyResponse::UpdateLobbyResponse(const std::string& message)
{
    m_successState = false;
    AppendMessage(message);
}
