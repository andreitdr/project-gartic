#pragma once

#include "../../../Infrastructure/BaseResponse.h"
#include <string>

class UpdateLobbyResponse final : public BaseResponse
{
public:
    UpdateLobbyResponse();
    UpdateLobbyResponse(const std::string& message);
};
