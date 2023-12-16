#pragma once
#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Infrastructure/Lobby/CreateLobbyRequest.h"
#include "../../Infrastructure/Lobby/CreateLobbyResponse.h"

#include <random>

#include "../BaseContext.h"

/**
 * \brief The minimum lobby ID that can be generated
 */
#define ID_MIN 100000

/**
 * \brief The maximum lobby ID that can be generated
 */
#define ID_MAX 9999999

class CreateLobbyContext final : public BaseContext<CreateLobbyRequest, CreateLobbyResponse>
{

public:
    CreateLobbyResponse HandleRequest(const CreateLobbyRequest& request) override;

private:
    CreateLobbyResponse ApplyChanges(const CreateLobbyRequest& request) override;
    
    bool LobbyExists(int lobbyId);
    uint32_t GenerateLobbyId();
};

inline uint32_t CreateLobbyContext::GenerateLobbyId()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(ID_MIN, ID_MAX);

    int generatedID = dis(gen);

    while (LobbyExists(generatedID))
        generatedID = dis(gen);
    
    return dis(gen);
}

inline CreateLobbyResponse CreateLobbyContext::HandleRequest(const CreateLobbyRequest& request)
{
    return ApplyChanges(request);
}

inline CreateLobbyResponse CreateLobbyContext::ApplyChanges(const CreateLobbyRequest& request)
{
    int userId = request.GetUserId();

    int lobbyId = GenerateLobbyId();

    const std::vector<int> userIds;
    const std::string str = JsonConvertor::ConvertFromVector(std::move(userIds)).dump();

    Lobby lobby = Lobby(-1, lobbyId, userId, std::move(str));
    
    int lobbyIndex = SqlDatabase::Insert<Lobby>(lobby);

    lobby.m_index = lobbyIndex;

    return CreateLobbyResponse(lobby);
}

inline bool CreateLobbyContext::LobbyExists(int lobbyId)
{
    return SqlDatabase::Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));
}

