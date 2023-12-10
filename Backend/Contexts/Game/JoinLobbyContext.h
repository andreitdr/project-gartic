
#pragma once
#include <vector>
#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "../BaseContext.h"

import JoinLobbyRequest;
import JoinLobbyResponse;

class JoinLobbyContext final : public BaseContext<JoinLobbyRequest, JoinLobbyResponse>
{
public:
    JoinLobbyResponse HandleRequest(const JoinLobbyRequest& request) override;

private:
    JoinLobbyResponse ValidateData(const JoinLobbyRequest& request);
	void ApplyChanges(const JoinLobbyRequest& request) override;
};

inline JoinLobbyResponse JoinLobbyContext::HandleRequest(const JoinLobbyRequest& request)
{
    	auto response = ValidateData(request);
    	if (response.m_successState == false)
    		return response;
    
    	ApplyChanges(request);
    
    	return response;
}

inline JoinLobbyResponse JoinLobbyContext::ValidateData(const JoinLobbyRequest& request)
{
	int lobbyId = request.GetLobbyId();
	try
	{
		
		if (!SqlDatabase::Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId)))
			throw std::system_error(sqlite_orm::orm_error_code::not_found);

		return JoinLobbyResponse();

	}
	catch (std::system_error error)
	{
		if(error.code() == sqlite_orm::orm_error_code::not_found)
		{
			return JoinLobbyResponse(std::format("Lobby with id {} was not found", lobbyId));
		}

		return JoinLobbyResponse(error.what());
	}
	
}

inline void JoinLobbyContext::ApplyChanges(const JoinLobbyRequest& request)
{
	int lobbyId = request.GetLobbyId();
	int playerId = request.GetUserId();

	
	Lobby currentLobby = SqlDatabase::Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

	std::vector<int> playersList = JsonConvertor::ConvertToVector<int>(currentLobby.m_userIds);
	playersList.emplace_back(playerId);
	currentLobby.m_userIds = JsonConvertor::ConvertFromVector(playersList).dump();

	SqlDatabase::Update(currentLobby);
}

