#include <crow.h>

#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "Contexts/Game/CreateLobbyContext.h"
#include "../../Lobby/CreateLobbyRequest.h"
#include "../../Lobby/CreateLobbyResponse.h"

inline crow::json::wvalue CreateLobby(const crow::json::rvalue& request)
{
    int lobbyId=static_cast<int>(request["Id"]);
    int userId=static_cast<int>(request["User"]);
    std::vector<int> users;
    CreateLobbyRequest m_request(lobbyId,userId);
    CreateLobbyResponse response=CreateLobbyContext::CreateLobby(m_request);

    crow::json::wvalue json;
    json = JsonConvertor::ConvertBaseResponse(response);
    users=CreateLobbyContext::ConvertToVector(response.GetUserIds());
    json["Id"]=response.GetLobbyId();
    json["Leader"]=response.GetLeaderId();
    json["UserIds"]=users;

    return json;
}