#pragma once
import BaseResponse;

#include <vector>
#include <string>

class CreateLobbyResponse: public BaseResponse
{
public:
    CreateLobbyResponse(int lobbyId,int leaderId, std::string userIds);
    CreateLobbyResponse(const std::string& message);

    int GetLobbyId();
    int GetLeaderId();
    std::string GetUserIds();

private:
    int m_lobbyId;
    int m_leaderId;
    std::string m_userIds;
};

CreateLobbyResponse::CreateLobbyResponse(int lobbyId, int leaderId, std::string userIds):
m_lobbyId{lobbyId},
m_leaderId{leaderId},
m_userIds{userIds}
{
    m_successState=true;
}

CreateLobbyResponse::CreateLobbyResponse(const std::string& message)
{
    m_successState=false;
    AppendMessage(message);
}

int CreateLobbyResponse::GetLobbyId()
{
    return m_lobbyId;
}

int CreateLobbyResponse::GetLeaderId()
{
    return m_leaderId;
}

std::string CreateLobbyResponse::GetUserIds()
{
    return m_userIds;
}
