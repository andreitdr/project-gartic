export module UserLoginRequest;

export import BaseRequest;
export import Credentials;
export __declspec(dllexport) class UserLoginRequest : BaseRequest<credentials>
{
public:
    UserLoginRequest(const credentials& userCredentails);
    credentials GetCredentials() const;
private:
    credentials m_userData;
};

UserLoginRequest::UserLoginRequest(const credentials& userCredentails) : BaseRequest<credentials>(userCredentails)
{
    
}

credentials UserLoginRequest::GetCredentials() const
{
    return m_userData;
}


