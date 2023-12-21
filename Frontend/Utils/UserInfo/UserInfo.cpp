#include "UserInfo.h"
#include "../../API/Requests/Requests.h"
#include "../../API/ResponseHandler/ResponseHandler.h"

UserInfo::UserInfo() : m_username{ "" }, m_givenName{ "" }, m_surname{ "" }, m_userId{ 0 } {}

UserInfo::UserInfo(const std::string& username, const std::string& givenName, const std::string& surname, const int userId)
    : m_username{username}, m_givenName{givenName}, m_surname{surname}, m_userId{ userId } {}

UserInfo::UserInfo(const UserInfo& other)
    : m_username{ other.m_username }, m_givenName{ other.m_givenName }, m_surname{ other.m_surname }, m_userId{ other.m_userId } {}

UserInfo::UserInfo(UserInfo&& other) noexcept 
    : m_username{ std::move(other.m_username) },
    m_givenName{ std::move(other.m_givenName) },
    m_surname{ std::move(other.m_surname) },
    m_userId{ other.m_userId }
{
  
}

UserInfo& UserInfo::operator=(const UserInfo& other) 
{
    if (this != &other) 
    {  
        m_username = other.m_username; 
        m_givenName = other.m_givenName;
        m_surname = other.m_surname;
        m_userId = other.m_userId;
    }
    return *this;
}

UserInfo& UserInfo::operator=(UserInfo&& other) noexcept 
{
    if (this != &other) {
        m_username = std::move(other.m_username);
        m_givenName = std::move(other.m_givenName);
        m_surname = std::move(other.m_surname);
        m_userId = other.m_userId;
    }
    return *this;
}


std::string UserInfo::getUsername() const {
    return m_username;
}

std::string UserInfo::getGivenName() const {
    return m_givenName;
}

std::string UserInfo::getSurname() const {
    return m_surname;
}

int UserInfo::getUserId() const
{
    return m_userId;
}

void UserInfo::setUsername(const std::string& username) {
    this->m_username = username;
}

void UserInfo::setGivenName(const std::string& givenName) {
    this->m_givenName = givenName;
}

void UserInfo::setSurname(const std::string& surname) {
    this->m_surname = surname;
}

void UserInfo::setUserId(int userId)
{
    this->m_userId = userId;
}