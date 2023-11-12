export module UserRegistrationRequest;

import <string>;
import BaseRequest;
import User;


export class __declspec(dllexport) UserRegistrationRequest : public BaseRequest<User>
{
    public:
        UserRegistrationRequest(const User& user);
};

UserRegistrationRequest::UserRegistrationRequest(const User& user) : BaseRequest(user)
{
    // Empty
}
