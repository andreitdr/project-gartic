export module UserRegisterResponse;

import BaseResponse;
import <optional>;
import <string>;

#include "../../Backend/User.h"


export class UserRegisterResponse : public BaseResponse
{
public:
    UserRegisterResponse(const std::string& message, bool state);
    UserRegisterResponse();
    void SetUser(const User& user);
    const std::optional<User> GetUser() const;
private:
    std::optional<User> m_user;
    

};

UserRegisterResponse::UserRegisterResponse(const std::string& message, bool state)
    : BaseResponse(message, state)
{
}

UserRegisterResponse::UserRegisterResponse() = default;

void UserRegisterResponse::SetUser(const User& user)
{
    m_user=user;
}

const std::optional<User> UserRegisterResponse::GetUser() const
{
    return m_user;
}
