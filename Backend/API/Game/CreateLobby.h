#pragma once
#include <crow.h>

#include "../../Infrastructure/Lobby/CreateLobbyRequest.h"
#include "../../Infrastructure/Lobby/CreateLobbyResponse.h"
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/CreateLobbyContext.h"

inline crow::json::wvalue CreateLobby(const crow::json::rvalue& request)
{
    const int userID = request["userId"].i();

    const CreateLobbyRequest createLobbyRequest = CreateLobbyRequest(userID);
    
    CreateLobbyContext context = CreateLobbyContext();

    const CreateLobbyResponse _response = context.HandleRequest(createLobbyRequest);
    WJSON response = JsonConvertor::ConvertBaseResponse(_response);

    const Lobby lobby = _response.GetLobby();
    response["Lobby"]["Id"] = lobby.m_lobbyId;
    response["Lobby"]["LeaderId"] = lobby.m_leaderId;
    response["Lobby"]["PlayerList"] = JsonConvertor::ConvertToVector<int>(lobby.m_userIds);

    return response;
}
