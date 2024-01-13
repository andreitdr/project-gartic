#pragma once
#include "../../BaseContext.h"
#include "../../../Infrastructure/GameManager/CheckWordRequest.h"
#include "../../../Infrastructure/GameManager/CheckWordResponse.h"

class CheckWordContext : public BaseContext<CheckWordRequest, CheckWordResponse>
{
public:
    CheckWordResponse HandleRequest(const CheckWordRequest& request) override;

public:
    CheckWordResponse ApplyChanges(const CheckWordRequest& request) override;
    CheckWordResponse ValidateData(const CheckWordRequest& request);
    
};
