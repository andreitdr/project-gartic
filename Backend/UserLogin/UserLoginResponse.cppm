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
    std::optional<credentials> GetCredentials();
    void SetCredentials(const credentials& credentials);
    void SetResponseState(bool state);
    
private:
    std::optional<credentials> m_credentials;
};

UserLoginResponse::UserLoginResponse() = default;

std::optional<credentials> UserLoginResponse::GetCredentials()
{
    return m_credentials;
}

void UserLoginResponse::SetCredentials(const credentials& credentials)
{
    this->m_credentials = credentials;
}

void UserLoginResponse::SetResponseState(bool state)
{
    BaseResponse::SetResponseState(state);
}

UserLoginResponse::UserLoginResponse(const std::string& message, bool state) : BaseResponse(message, state) 
{}

