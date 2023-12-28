#include "../GetLobbyStatusContext.h"

#include "../../../../SqlDatabase/SqlDatabase.h"
#include "../../../../Infrastructure/Lobby/Status/GetLobbyStatusRequest.h"
#include "../../../../Infrastructure/Lobby/Status/GetLobbyStatusResponse.h"


bool GetLobbyStatusContext::ValidateLobbyExists(int lobbyId)
{
    if(!SqlDatabase::Exists<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId))) return false;
    return true;
}


GetLobbyStatusResponse GetLobbyStatusContext::HandleRequest(const GetLobbyStatusRequest& request)
{
    const int lobbyId = request.GetLobbyId();
    
    if(!ValidateLobbyExists(lobbyId))
        return GetLobbyStatusResponse("Lobby does not exist");

    return ApplyChanges(request);
}

GetLobbyStatusResponse GetLobbyStatusContext::ApplyChanges(const GetLobbyStatusRequest& request)
{
    try
    {
        const Lobby lobby = SqlDatabase::Get<Lobby>(WHERE(Lobby::m_lobbyId, request.GetLobbyId()));
        
        return GetLobbyStatusResponse(lobby);
    }
    catch (const std::exception& err)
    {
        return GetLobbyStatusResponse(err.what());
    }

}
