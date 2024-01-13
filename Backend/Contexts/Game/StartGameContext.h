﻿#pragma once

#include "../../SqlDatabase/SqlDatabase.h"
#include "../../Infrastructure/GameStart/StartGameRequest.h"
#include "../../Infrastructure/GameStart/StartGameResponse.h"
#include "../BaseContext.h"

class StartGameContext final : public BaseContext<StartGameRequest, StartGameResponse>
{
public:
    StartGameResponse HandleRequest(const StartGameRequest& request) override;

private:
    StartGameResponse ApplyChanges(const StartGameRequest& request) override;
    std::vector<std::string> GenerateWords(size_t count);
};

