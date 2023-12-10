#pragma once
#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Infrastructure/Lobby/CreateLobbyRequest.h"
#include "../../Infrastructure/Lobby/CreateLobbyResponse.h"

#include <random>

/**
 * \brief The minimum lobby ID that can be generated
 */
#define ID_MIN 100000

/**
 * \brief The maximum lobby ID that can be generated
 */
#define ID_MAX 9999999

class CreateLobbyContext
{
public:
    static CreateLobbyResponse CreateLobby(const CreateLobbyRequest& request);
private:
    static bool LobbyExists(int lobbyId);
    static void InsertLobby(const Lobby& lobby);
    static int GenerateLobbyId();
};

inline CreateLobbyResponse CreateLobbyContext::CreateLobby(const CreateLobbyRequest& request)
{
    int userId = request.GetUserId();

    int lobbyId = GenerateLobbyId();

    const std::vector<int> userIds;
    const std::string str = JsonConvertor::ConvertFromVector(std::move(userIds)).dump();

    Lobby lobby = Lobby(-1, lobbyId, userId, std::move(str));

    InsertLobby(lobby);

    return CreateLobbyResponse(lobby);
}

inline bool CreateLobbyContext::LobbyExists(int lobbyId)
{
    return SqlDatabase::Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));
}

inline void CreateLobbyContext::InsertLobby(const Lobby& lobby)
{
    SqlDatabase::Insert<Lobby>(lobby);
}

inline int CreateLobbyContext::GenerateLobbyId()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(ID_MIN, ID_MAX);

    int generatedID = dis(gen);

    while (LobbyExists(generatedID))
        generatedID = dis(gen);
    
    return dis(gen);
}

