#pragma once

#include <crow.h>
#include "../../Contexts/Game/GameManagement/GetChatMessagesContext.h"
#include "../../Utils/JsonConvertor.h"

inline WJSON GetChatMessages(const crow::json::rvalue& request)
{
    const int gameId = request["gameId"].i();
    GetChatMessagesRequest getChatMessagesRequest {gameId};
    GetChatMessagesContext getChatMessagesContext{};

    GetChatMessagesResponse getChatMessagesResponse = getChatMessagesContext.HandleRequest(getChatMessagesRequest);
    WJSON jsonResult = JsonConvertor::ConvertBaseResponse(getChatMessagesResponse);
    jsonResult["ChatMessages"] = getChatMessagesResponse.GetMessages();

    return jsonResult;
}