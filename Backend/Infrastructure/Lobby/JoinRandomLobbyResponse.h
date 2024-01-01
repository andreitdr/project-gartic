#pragma once

import BaseResponse;
#include <string>

class JoinRandomLobbyResponse final : public BaseResponse
{
public:
    JoinRandomLobbyResponse();
    JoinRandomLobbyResponse(const std::string& message);
};
