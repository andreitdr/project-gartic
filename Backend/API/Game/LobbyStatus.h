#pragma once
#include "../../Contexts/Game/Lobby/GetLobbyStatusContext.h"
#include "../../Utils/JsonConvertor.h"


inline WJSON GetLobbyStatus(const crow::json::rvalue& request)
{
    int lobbyId = request["lobbyId"].i();

    GetLobbyStatusRequest getLobbyStatusRequest(lobbyId);
    auto getLobbyStatusContext                    = GetLobbyStatusContext();
    GetLobbyStatusResponse getLobbyStatusResponse = getLobbyStatusContext.HandleRequest(getLobbyStatusRequest);

    WJSON response                  = JsonConvertor::ConvertBaseResponse(getLobbyStatusResponse);
    const Lobby lobby               = getLobbyStatusResponse.GetLobby();
    response["Lobby"]["Id"]         = lobby.m_lobbyId;
    response["Lobby"]["LeaderId"]   = lobby.m_leaderId;
    response["Lobby"]["PlayerList"] = JsonConvertor::ConvertToVector<int>(lobby.m_userIds);
    response["Lobby"]["LobbyType"]  = lobby.m_lobbyType;
    response["Lobby"]["IsPrivate"]  = lobby.m_isPrivate;
    response["Lobby"]["IsStarted"]  = lobby.m_isStarted;

    return response;
}
