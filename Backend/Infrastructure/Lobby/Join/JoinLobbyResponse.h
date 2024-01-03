#pragma once
#include <string>

#include "../../../Infrastructure/BaseResponse.h"

class JoinLobbyResponse final : public BaseResponse
{
public:
    JoinLobbyResponse();
    JoinLobbyResponse(const std::string& message);
};
