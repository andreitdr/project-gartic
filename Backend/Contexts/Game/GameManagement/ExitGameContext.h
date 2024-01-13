#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/ExitGameRequest.h"
#include "../../../Infrastructure/GameManager/ExitGameResponse.h"

class ExitGameContext final : public BaseContext<ExitGameRequest,ExitGameResponse>
{
public:
    ExitGameResponse HandleRequest(const ExitGameRequest& request) override;
private:
    ExitGameResponse ApplyChanges(const ExitGameRequest& request) override;
    
};
