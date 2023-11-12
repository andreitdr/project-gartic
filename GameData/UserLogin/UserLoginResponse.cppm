export module UserLoginResponse;
import <string>;
import <optional>;


export import BaseResponse;
export import User;
export import Credentials;


export __declspec(dllexport) class UserLoginResponse : BaseResponse
{
public:
    UserLoginResponse(const std::string& message, bool state);
    UserLoginResponse();
    std::optional<credentials> GetCredentials();
    void SetCredentials(const credentials& credentials);
private:
    std::optional<credentials> m_credentials_;
};

UserLoginResponse::UserLoginResponse() = default;

std::optional<credentials> UserLoginResponse::GetCredentials()
{
    return m_credentials_;
}

void UserLoginResponse::SetCredentials(const credentials& credentials)
{
    this->m_credentials_ = credentials;
}

UserLoginResponse::UserLoginResponse(const std::string& message, bool state) : BaseResponse(message, state) 
{}

