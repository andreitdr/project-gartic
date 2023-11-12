export module UserLoginResponse;
import <string>;
import <optional>;


export import BaseResponse;
export import User;


export __declspec(dllexport) class UserLoginResponse : BaseResponse
{
public:
    UserLoginResponse(const std::string& message, bool state);
    UserLoginResponse();
    std::optional<User> GetUser();
private:
    std::optional<User> m_user;
};

UserLoginResponse::UserLoginResponse() = default;

UserLoginResponse::UserLoginResponse(const std::string& message, bool state) : BaseResponse(message, state) 
{}

