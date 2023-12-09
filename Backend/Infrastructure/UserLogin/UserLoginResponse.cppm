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


