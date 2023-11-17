export module UserRegisterResponse;
import <optional>;
import <string>;


export import User;
export import BaseResponse;
export class __declspec(dllexport) UserRegisterResponse : public BaseResponse
{
public:
    UserRegisterResponse(const std::string& message, bool state);
    UserRegisterResponse();
    void SetUser(const UserStructModel& user);
    std::optional<UserStructModel> GetUser() const;
private:
    std::optional<UserStructModel> m_user;
};

UserRegisterResponse::UserRegisterResponse(const std::string& message, bool state)
    : BaseResponse(message, state)
{
}

UserRegisterResponse::UserRegisterResponse() : BaseResponse()
{
}

void UserRegisterResponse::SetUser(const UserStructModel& user)
{
    m_user=user;
}

std::optional<UserStructModel> UserRegisterResponse::GetUser() const
{
    return m_user;
}
