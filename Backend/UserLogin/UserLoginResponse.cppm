export module UserLoginResponse;
import <string>;
import <optional>;


export import BaseResponse;
export import User;
export import Credentials;


export class UserLoginResponse : public BaseResponse
{
public:
    UserLoginResponse(const std::string& message, bool state);
    UserLoginResponse(bool state);
    
    std::optional<Credentials> GetCredentials();
    void SetCredentials(const Credentials& credentials);
    
private:
    std::optional<Credentials> m_credentials;
};

UserLoginResponse::UserLoginResponse(const std::string& message, bool state)
{
    AppendMessage(message);
    m_successState = state;
}

UserLoginResponse::UserLoginResponse(bool state) : BaseResponse()
{
    m_successState = state;
}

std::optional<Credentials> UserLoginResponse::GetCredentials()
{
    return m_credentials;
}

void UserLoginResponse::SetCredentials(const Credentials& credentials)
{
    m_credentials = credentials;
}




