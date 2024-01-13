#include "CreateLobbyContext.h"

#include "../../../SqlDatabase/SqlDatabase.h"
#include "../../../Utils/JsonConvertor.h"

#include <random>
 uint32_t CreateLobbyContext::GenerateLobbyId()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lobby_id_min, lobby_id_max);

    int generatedID = dis(gen);

    while (LobbyExists(generatedID)) generatedID = dis(gen);

    return dis(gen);
}

 CreateLobbyResponse CreateLobbyContext::HandleRequest(const CreateLobbyRequest& request)
{
    return ApplyChanges(request);
}

 CreateLobbyResponse CreateLobbyContext::ApplyChanges(const CreateLobbyRequest& request)
{
    int userId = request.GetUserId();

    int lobbyId = GenerateLobbyId();

    const std::vector<int> userIds = {userId};
    const std::string str          = JsonConvertor::ConvertFromVector(std::move(userIds)).dump();

    auto lobby = Lobby(-1, lobbyId, userId, request.GetLobbyType(), request.GetIsPrivate(), std::move(str));

    int lobbyIndex = SqlDatabase::GetInstance().GetInstance().Insert<Lobby>(lobby);

    lobby.m_index = lobbyIndex;

    return CreateLobbyResponse(lobby);
}

 bool CreateLobbyContext::LobbyExists(int lobbyId)
{
    return SqlDatabase::GetInstance().GetInstance().Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));
}
