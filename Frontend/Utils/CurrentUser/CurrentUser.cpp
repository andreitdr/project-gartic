#include "CurrentUser.h"

CurrentUser::CurrentUser() : m_username(""), m_givenName(""), m_surname(""), m_userId(0) {}

CurrentUser& CurrentUser::getInstance() {
    static CurrentUser instance;
    return instance;
}

void CurrentUser::setUsername(const std::string& username) {
    m_username = username;
}
std::string CurrentUser::getUsername() const {
    return m_username;
}

void CurrentUser::setGivenName(const std::string& givenName) {
    m_givenName = givenName;
}
std::string CurrentUser::getGivenName() const {
    return m_givenName;
}

void CurrentUser::setSurname(const std::string& surname) {
    m_surname = surname;
}
std::string CurrentUser::getSurname() const {
    return m_surname;
}

void CurrentUser::setUserId(int userId) {
    m_userId = userId;
}
int CurrentUser::getUserId() const {
    return m_userId;
}
