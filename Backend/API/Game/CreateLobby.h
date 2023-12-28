#pragma once
#include <crow.h>

#include "../../Infrastructure/Lobby/CreateLobbyRequest.h"
#include "../../Infrastructure/Lobby/CreateLobbyResponse.h"
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/CreateLobbyContext.h"

inline crow::json::wvalue CreateLobby(const crow::json::rvalue& request)
{
    const int userID = request["userId"].i();
    const int lobbyType = request["lobbyType"].i();
    const bool isPrivateLobby = request["isPrivateLobby"].b();

    const CreateLobbyRequest createLobbyRequest = CreateLobbyRequest(userID, lobbyType, isPrivateLobby);
    
    CreateLobbyContext context = CreateLobbyContext();

    const CreateLobbyResponse _response = context.HandleRequest(createLobbyRequest);
    WJSON response = JsonConvertor::ConvertBaseResponse(_response);

    const Lobby lobby = _response.GetLobby();
    response["Lobby"]["Id"] = lobby.m_lobbyId;
    response["Lobby"]["LeaderId"] = lobby.m_leaderId;
    response["Lobby"]["LobbyType"] = lobby.m_lobbyType;
    response["Lobby"]["IsPrivate"] = lobby.m_isPrivate;
    response["Lobby"]["PlayerList"] = JsonConvertor::ConvertToVector<int>(lobby.m_userIds);

    return response;
}
