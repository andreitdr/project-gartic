export module UserLoginResponse;
import <string>;
import <optional>;


export import BaseResponse;
export import User;
export import Credentials;


export class UserLoginResponse : BaseResponse
{
public:
    UserLoginResponse(const std::string& message, bool state);
    UserLoginResponse();
    
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

UserLoginResponse::UserLoginResponse() : BaseResponse()
{
}

std::optional<Credentials> UserLoginResponse::GetCredentials()
{
    return m_credentials;
}

void UserLoginResponse::SetCredentials(const Credentials& credentials)
{
    m_credentials = credentials;
}




