#include "UserInfo.h"

UserInfo::UserInfo() : username(""), givenName(""), surname("") {}

UserInfo::UserInfo(const std::string& username, const std::string& givenName, const std::string& surname)
    : username(username), givenName(givenName), surname(surname) {}

UserInfo::UserInfo(const UserInfo& other)
    : username(other.username), givenName(other.givenName), surname(other.surname) {}

std::string UserInfo::getUsername() const {
    return username;
}

std::string UserInfo::getGivenName() const {
    return givenName;
}

std::string UserInfo::getSurname() const {
    return surname;
}

void UserInfo::setUsername(const std::string& username) {
    this->username = username;
}

void UserInfo::setGivenName(const std::string& givenName) {
    this->givenName = givenName;
}

void UserInfo::setSurname(const std::string& surname) {
    this->surname = surname;
}