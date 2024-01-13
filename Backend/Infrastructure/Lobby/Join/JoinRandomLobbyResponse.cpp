#include "JoinRandomLobbyResponse.h"

JoinRandomLobbyResponse::JoinRandomLobbyResponse(int lobbyId) : BaseResponse{true}, m_lobbyId{lobbyId}
{
}

JoinRandomLobbyResponse::JoinRandomLobbyResponse(const std::string &message) : BaseResponse{false}
{
    AppendMessage(message);
}

JoinRandomLobbyResponse::JoinRandomLobbyResponse(bool state) : BaseResponse{state}
{
}

int JoinRandomLobbyResponse::GetLobbyId() const
{
    return m_lobbyId;
}
