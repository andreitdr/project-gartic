export module UserRegistrationRequest;

import <string>;

export import User;
export import Credentials;

export class UserRegistrationRequest
{
public:
    UserRegistrationRequest(const UserStructModel& user, const Credentials& userCredentials);
    Credentials GetCredentials() const;
    UserStructModel GetUser() const;
    
private:
    Credentials m_userCredentials;
    UserStructModel m_user;
};


UserRegistrationRequest::UserRegistrationRequest(const UserStructModel& user, const Credentials& userCredentials) :
m_userCredentials(userCredentials), m_user(user)
{
}

Credentials UserRegistrationRequest::GetCredentials() const
{
    return m_userCredentials;
}

UserStructModel UserRegistrationRequest::GetUser() const
{
    return m_user;
}
