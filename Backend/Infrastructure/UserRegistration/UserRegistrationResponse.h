#pragma once
#include <string>
#include <optional>

#include "../../Infrastructure/BaseResponse.h"
#include "../../DataTypes/User/User.h"

class UserRegistrationResponse : public BaseResponse
{
public:
    UserRegistrationResponse(const std::string& message, bool state);
    UserRegistrationResponse();

    void SetUser(const User& user);
    std::optional<User> GetUser() const;

private:
    std::optional<User> m_user;
};
