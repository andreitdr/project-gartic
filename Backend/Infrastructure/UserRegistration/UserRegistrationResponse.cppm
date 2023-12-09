export module UserRegisterResponse;
import <optional>;
import <string>;


export import User;
export import BaseResponse;

export class UserRegistrationResponse : public BaseResponse
{
public:
    UserRegistrationResponse(const std::string& message, bool state);
    UserRegistrationResponse();
    
    void SetUser(const User& user);
    std::optional<User> GetUser() const;
    
private:
    std::optional<User> m_user;
};

UserRegistrationResponse::UserRegistrationResponse(const std::string& message, bool state)
{
    AppendMessage(message);
    m_successState = state;
}

UserRegistrationResponse::UserRegistrationResponse() : BaseResponse()
{
}

void UserRegistrationResponse::SetUser(const User& user)
{
    m_user=user;
}

std::optional<User> UserRegistrationResponse::GetUser() const
{
    return m_user;
}
