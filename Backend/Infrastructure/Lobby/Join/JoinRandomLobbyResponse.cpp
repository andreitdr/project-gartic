#include "JoinRandomLobbyResponse.h"

JoinRandomLobbyResponse::JoinRandomLobbyResponse(int lobbyId) : BaseResponse{true}, m_lobbyId{lobbyId}
{
}

JoinRandomLobbyResponse::JoinRandomLobbyResponse(const std::string &message) : BaseResponse{false}, m_lobbyId{-1}
{
    AppendMessage(message);
}

JoinRandomLobbyResponse::JoinRandomLobbyResponse(bool state) : BaseResponse{state}, m_lobbyId{-1}
{
}

int JoinRandomLobbyResponse::GetLobbyId() const
{
    return m_lobbyId;
}
