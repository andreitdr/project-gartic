import <optional>;
import <string>;

export module UserRegisterResponse;

export import User;
export import BaseResponse;
export class __declspec(dllexport) UserRegisterResponse : public BaseResponse
{
public:
    UserRegisterResponse(const std::string& message, bool state);
    UserRegisterResponse();
    void SetUser(const User& user);
    std::optional<User> GetUser() const;
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

std::optional<User> UserRegisterResponse::GetUser() const
{
    return m_user;
}
