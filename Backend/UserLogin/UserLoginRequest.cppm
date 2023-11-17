export module UserLoginRequest;

export import BaseRequest;
export import Credentials;

export __declspec(dllexport) class UserLoginRequest : BaseRequest<credentials>
{
public:
    UserLoginRequest(const credentials& userCredentails);
    credentials GetObject() const;

};

UserLoginRequest::UserLoginRequest(const credentials& userCredentails) : BaseRequest<credentials>(userCredentails)
{
    
}

credentials UserLoginRequest::GetObject() const
{
    return BaseRequest<credentials>::GetObject();
}
