export module UserRegistrationRequest;

import <string>;
import BaseRequest;
import User;


export class __declspec(dllexport) UserRegistrationRequest : public BaseRequest<UserStructModel>
{
    public:
        UserRegistrationRequest(const UserStructModel& user);
};

UserRegistrationRequest::UserRegistrationRequest(const UserStructModel& user) : BaseRequest(user)
{
    // Empty
}
