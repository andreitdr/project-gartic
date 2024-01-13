#include "JoinRandomLobbyContext.h"
#include <random>
#include "../../../SqlDatabase/SqlDatabase.h"
#include "../../../Utils/JsonConvertor.h"

int random(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int JoinRandomLobbyContext::GetRandomLobbyId() const
{
    std::vector<Lobby> lobbies = SqlDatabase::GetInstance().GetAll<Lobby>(WHERE(Lobby::m_isPrivate, false));
    if(lobbies.empty())
        return -1;

    int index = random(0, lobbies.size() - 1);
    return lobbies[index].m_lobbyId;
}


JoinRandomLobbyResponse JoinRandomLobbyContext::HandleRequest(const JoinRandomLobbyRequest& request)
{
    auto response = ValidateData(request);
    if(!response)
        return response;

    return ApplyChanges(request);
}

JoinRandomLobbyResponse JoinRandomLobbyContext::ApplyChanges(const JoinRandomLobbyRequest& request)
{
    int lobbyId = GetRandomLobbyId();
    if(lobbyId == -1)
        return JoinRandomLobbyResponse("No lobbies available");

    auto currentLobby = SqlDatabase::GetInstance().Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

    std::vector<int> playersList = JsonConvertor::ConvertToVector<int>(currentLobby.m_userIds);
    playersList.emplace_back(request.GetUserId());
    currentLobby.m_userIds = JsonConvertor::ConvertFromVector(playersList).dump();

    SqlDatabase::GetInstance().Update(currentLobby);

    return JoinRandomLobbyResponse(lobbyId);
}

JoinRandomLobbyResponse JoinRandomLobbyContext::ValidateData(const JoinRandomLobbyRequest& request)
{
    int userId = request.GetUserId();

    if(!SqlDatabase::GetInstance().Exists<User>(userId))
        return JoinRandomLobbyResponse("User does not exist");

    return JoinRandomLobbyResponse(true);
}

