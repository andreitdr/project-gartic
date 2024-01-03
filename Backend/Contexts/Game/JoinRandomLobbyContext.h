#pragma once

#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"

#include "../../Infrastructure/Lobby/Join/JoinRandomLobbyRequest.h"
#include "../../Infrastructure/Lobby/Join/JoinRandomLobbyResponse.h"

#include "../BaseContext.h"
#include <random>

class JoinRandomLobbyContext final : public BaseContext<JoinRandomLobbyRequest, JoinRandomLobbyResponse>
{
public:
    JoinRandomLobbyResponse HandleRequest(const JoinRandomLobbyRequest& request) override;

private:
    JoinRandomLobbyResponse ApplyChanges(const JoinRandomLobbyRequest& request) override;
};

inline JoinRandomLobbyResponse JoinRandomLobbyContext::HandleRequest(const JoinRandomLobbyRequest& request)
{
    return ApplyChanges(request);
}

inline JoinRandomLobbyResponse JoinRandomLobbyContext::ApplyChanges(const JoinRandomLobbyRequest& request)
{
    try
    {
        int userId = request.GetUserId();
        
        auto allLobbies = SqlDatabase::GetAll<Lobby>(sqlite_orm::where(sqlite_orm::c(&Lobby::m_index) > 0));

        if (!allLobbies.empty())
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<size_t> dis(0, allLobbies.size() - 1);

            size_t randomIndex = dis(gen);

            Lobby randomLobby = allLobbies[randomIndex];

            std::vector<int> userIds = JsonConvertor::ConvertToVector<int>(randomLobby.m_userIds);
            userIds.emplace_back(userId);
            randomLobby.m_userIds = JsonConvertor::ConvertFromVector(userIds).dump();

            SqlDatabase::Update(randomLobby);

            return JoinRandomLobbyResponse();
        }
        else
        {
            return JoinRandomLobbyResponse("No available lobbies found.");
        }
    }
    catch (const std::system_error& error)
    {
        return JoinRandomLobbyResponse(error.what());
    }
}
