#pragma once

#include <crow.h>
#include "../../Infrastructure/Lobby/UpdateLobbyRequest.h"
#include "../../Infrastructure/Lobby/UpdateLobbyResponse.h"
#include "../../Utils/JsonConvertor.h"
#include "../../Contexts/Game/UpdateLobbyContext.h"

inline crow::json::wvalue UpdateLobby(const crow::json::rvalue& request)
{
	const int lobbyId = request["lobbyId"].i();
	const int newLeaderId = request["userId"].i();

	const UpdateLobbyRequest updateLobbyRequest(lobbyId, newLeaderId);
	UpdateLobbyContext updateLobbyContext{};
	const UpdateLobbyResponse updateLobbyResponse = updateLobbyContext.HandleRequest(updateLobbyRequest);

	WJSON json = JsonConvertor::ConvertBaseResponse(updateLobbyResponse);
	return json;
}
