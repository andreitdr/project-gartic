#pragma once

#include "../../Infrastructure/Lobby/UpdateLobbyRequest.h"
#include "../../Infrastructure/Lobby/UpdateLobbyResponse.h"
#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Utils/JsonConvertor.h"
#include "../BaseContext.h"

class UpdateLobbyContext final : public BaseContext<UpdateLobbyRequest, UpdateLobbyResponse>
{
public:
    UpdateLobbyResponse HandleRequest(const UpdateLobbyRequest& request);

private:
    UpdateLobbyResponse ValidateData(const UpdateLobbyRequest& request);
    UpdateLobbyResponse ApplyChanges(const UpdateLobbyRequest& request);
};

inline UpdateLobbyResponse UpdateLobbyContext::HandleRequest(const UpdateLobbyRequest& request)
{
    auto response = ValidateData(request);
    if (!response.GetSuccessState())
        return response;

    ApplyChanges(request);

    return response;
}