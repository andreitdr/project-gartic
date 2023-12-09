export module UserRegistrationRequest;

import <string>;

export import User;
export import Credentials;

export class UserRegistrationRequest
{
public:
    UserRegistrationRequest(const User& user, const Credentials& userCredentials);
    Credentials GetCredentials() const;
    User GetUser() const;
    
private:
    Credentials m_userCredentials;
    User m_user;
};


UserRegistrationRequest::UserRegistrationRequest(const User& user, const Credentials& userCredentials) :
m_userCredentials(userCredentials), m_user(user)
{
}

Credentials UserRegistrationRequest::GetCredentials() const
{
    return m_userCredentials;
}

User UserRegistrationRequest::GetUser() const
{
    return m_user;
}
