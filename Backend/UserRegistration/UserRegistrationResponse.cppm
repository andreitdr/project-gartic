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
    
    void SetUser(const UserStructModel& user);
    std::optional<UserStructModel> GetUser() const;
    
private:
    std::optional<UserStructModel> m_user;
};

UserRegistrationResponse::UserRegistrationResponse(const std::string& message, bool state)
{
    AppendMessage(message);
    m_successState = state;
}

UserRegistrationResponse::UserRegistrationResponse() : BaseResponse()
{
}

void UserRegistrationResponse::SetUser(const UserStructModel& user)
{
    m_user=user;
}

std::optional<UserStructModel> UserRegistrationResponse::GetUser() const
{
    return m_user;
}
