#pragma once

#include <string>

#include "../../BaseResponse.h"

class JoinRandomLobbyResponse final : public BaseResponse
{
public:
    JoinRandomLobbyResponse();
    JoinRandomLobbyResponse(const std::string& message);
};

