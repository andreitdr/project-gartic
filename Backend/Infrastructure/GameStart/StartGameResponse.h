#pragma once
#include <string>

#include "../../Infrastructure/BaseResponse.h"


class StartGameResponse : public BaseResponse
{
public:
    StartGameResponse(int gameID);
    StartGameResponse(const std::string& message);

    int GetGameID() const;

private:
    int m_gameID;
};
