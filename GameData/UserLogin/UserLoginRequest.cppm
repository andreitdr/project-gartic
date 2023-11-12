export module UserLoginRequest;

export import BaseRequest;
export import Credentials;

export __declspec(dllexport) class UserLoginRequest : BaseRequest<credentials>
{
public:
    UserLoginRequest(const credentials& userCredentails);

};

UserLoginRequest::UserLoginRequest(const credentials& userCredentails) : BaseRequest<credentials>(userCredentails)
{
    
}
