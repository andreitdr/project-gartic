#include "JoinRandomLobbyContext.h"
#include <random>
#include "../../../SqlDatabase/SqlDatabase.h"
#include "../../../Utils/JsonConvertor.h"

JoinRandomLobbyResponse JoinRandomLobbyContext::HandleRequest(const JoinRandomLobbyRequest& request)
{
    return ApplyChanges(request);
}

 JoinRandomLobbyResponse JoinRandomLobbyContext::ApplyChanges(const JoinRandomLobbyRequest& request)
{
    try
    {
        int userId = request.GetUserId();
        
        auto allLobbies = SqlDatabase::GetInstance().GetAll<Lobby>(WHERE(Lobby::m_isPrivate, false));

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

            SqlDatabase::GetInstance().Update(randomLobby);

            return JoinRandomLobbyResponse();
        }

        return JoinRandomLobbyResponse("No available lobbies found.");
    }
    catch (const std::system_error& error)
    {
        return JoinRandomLobbyResponse(error.what());
    }
}
