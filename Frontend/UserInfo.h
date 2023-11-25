#pragma once
#include <string>
class UserInfo
{
public:
    UserInfo();
    UserInfo(const std::string& username, const std::string& givenName, const std::string& surname);
    UserInfo(const UserInfo& other);

    std::string getUsername() const;
    std::string getGivenName() const;
    std::string getSurname() const;

    void setUsername(const std::string& username);
    void setGivenName(const std::string& givenName);
    void setSurname(const std::string& surname);

private:
    std::string username;
    std::string givenName;
    std::string surname;
};

