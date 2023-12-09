export module UserLoginRequest;

export import Credentials;

export class UserLoginRequest
{
public:
    UserLoginRequest(const Credentials& userCredentails);
    Credentials GetCredentials() const;

private:
    Credentials m_userCredentials;

};

UserLoginRequest::UserLoginRequest(const Credentials& userCredentails) : m_userCredentials(userCredentails)
{
    
}

Credentials UserLoginRequest::GetCredentials() const
{
    return m_userCredentials;
}
