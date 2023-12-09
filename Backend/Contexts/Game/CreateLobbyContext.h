#pragma once
#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "../../Infrastructure/Lobby/CreateLobbyRequest.h"
#include "../../Infrastructure/Lobby/CreateLobbyResponse.h"


class CreateLobbyContext
{
public:
    static CreateLobbyResponse CreateLobby(const CreateLobbyRequest& request);

    static std::vector<int> ConvertToVector(std::string str);
private:
    static bool LobbyExists(int lobbyId);
};

CreateLobbyResponse CreateLobbyContext::CreateLobby(const CreateLobbyRequest& request)
{
    int lobbyId = request.GetLobbyId();
    if (!LobbyExists(lobbyId))
    {
        try
        {
            auto lobby = Lobby();
            lobby.m_lobbyId = lobbyId;
            lobby.m_leaderId = request.GetUserId();
            std::vector<int> users;
            users.push_back(request.GetUserId());
            lobby.m_userIds = JsonConvertor::ConvertFromVector<int>(users).dump();
            int lobbyId = SqlDatabase::Insert(lobby);
            auto response = CreateLobbyResponse(lobbyId, lobby.m_leaderId, lobby.m_userIds);
            return response;
        }
        catch (const std::exception& e)
        {
            return CreateLobbyResponse(e.what());
        }
    }
    try
    {
        auto leader = storage.select(sqlite_orm::columns(&Lobby::m_leaderId),
                                     sqlite_orm::where(sqlite_orm::c(&Lobby::m_lobbyId) == lobbyId));
        auto past_users = storage.select(sqlite_orm::columns(&Lobby::m_userIds),
                                         sqlite_orm::where(sqlite_orm::c(&Lobby::m_lobbyId) == lobbyId));
        auto lobby = Lobby();
        lobby = storage.get<Lobby>(sqlite_orm::where(sqlite_orm::c(&Lobby::m_lobbyId) == lobbyId));
        std::vector<int> users = ConvertToVector(lobby.m_userIds);
        users.push_back(request.GetUserId());
        lobby.m_userIds=JsonConvertor::ConvertFromVector<int>(users).dump();
        bool update = SqlDatabase::Update(lobby);
        auto response = CreateLobbyResponse(lobby.m_lobbyId, lobby.m_leaderId, lobby.m_userIds);
        return response;
    }
    catch (const std::exception& e)
    {
        return CreateLobbyResponse(e.what());
    }
}

bool CreateLobbyContext::LobbyExists(int lobbyId)
{
    return storage.count<Lobby>(sqlite_orm::where(sqlite_orm::c(&Lobby::m_lobbyId) == lobbyId)) != 0;
}

inline std::vector<int> CreateLobbyContext::ConvertToVector(std::string str)
{
    auto j = crow::json::load(str);

    std::vector<int> v;
    for (const auto& item : j)
    {
        v.push_back(item.i());
    }
    return v;
}
