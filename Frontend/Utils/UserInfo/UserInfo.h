#pragma once
#include <string>

class UserInfo
{
public:
    UserInfo();
    UserInfo(const std::string& username, const std::string& givenName, const std::string& surname, const int userId);
    UserInfo(const UserInfo& other);

    UserInfo(UserInfo&& other) noexcept;

    UserInfo& operator=(const UserInfo& other);  
    UserInfo& operator=(UserInfo&& other) noexcept;

    std::string getUsername() const;
    std::string getGivenName() const;
    std::string getSurname() const;
    int getUserId() const;

    void setUsername(const std::string& username);
    void setGivenName(const std::string& givenName);
    void setSurname(const std::string& surname);
    void setUserId(int userId);

private:
    std::string m_username;
    std::string m_givenName;
    std::string m_surname;
    int m_userId;
};

