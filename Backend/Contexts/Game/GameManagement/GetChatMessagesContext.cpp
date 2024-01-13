#include "GetChatMessagesContext.h"
#include "../../../GameManagement/GameManager.h"

GetChatMessagesResponse GetChatMessagesContext::HandleRequest(const GetChatMessagesRequest& request)
{
    auto response = ValidateData(request);
    if(!response)
        return response;

    return ApplyChanges(request);
}

GetChatMessagesResponse GetChatMessagesContext::ApplyChanges(const GetChatMessagesRequest& request)
{
    int gameId = request.GetGameId();
    const std::vector<std::string> chatMessages = GameManager::GetInstance().GetChat(gameId);
    return GetChatMessagesResponse(chatMessages);
}

GetChatMessagesResponse GetChatMessagesContext::ValidateData(const GetChatMessagesRequest& request)
{
    int gameId = request.GetGameId();

    if(!GameManager::GetInstance().GameExists(gameId))
        return GetChatMessagesResponse("Game does not exist", false);

    return GetChatMessagesResponse(true);
}
