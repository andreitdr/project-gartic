#pragma once
#include <string>
#include <mutex>

class CurrentUser {
public:
    static CurrentUser& getInstance();

    void setUsername(const std::string& username);
    std::string getUsername() const;

    void setGivenName(const std::string& givenName);
    std::string getGivenName() const;

    void setSurname(const std::string& surname);
    std::string getSurname() const;

    void setUserId(int userId);
    int getUserId() const;

    CurrentUser(const CurrentUser&) = delete;
    CurrentUser& operator=(const CurrentUser&) = delete;

private:
    CurrentUser();
    std::mutex m_currentUserMutex;
    std::string m_username;
    std::string m_givenName;
    std::string m_surname;
    int m_userId;
};
