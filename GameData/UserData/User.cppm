export module User;

import <string>;

export __declspec(dllexport) class User
{
public:
    friend class UserRegister;
    std::string getSurname() const;
    std::string getGivenName() const;
    std::string getUsername() const;
    int getUserID() const;

private:
    std::string m_surname;
    std::string m_givenName;
    std::string m_username;
    int m_user_id;

    size_t GenerateUserId(const std::string& username);
    User(const std::string& surname, const std::string& givenName, const std::string& username);
};

int User::getUserID() const
{
    return m_user_id;
}

std::string User::getSurname() const
{
    return m_surname;
}

std::string User::getGivenName() const
{
    return m_givenName;
}

std::string User::getUsername() const
{
    return m_username;
}

size_t User::GenerateUserId(const std::string& username)
{
    std::hash<std::string> hasher;
    return hasher(username);
}

User::User(const std::string& surname, const std::string& givenName, const std::string& username)
    : m_surname(surname), m_givenName(givenName), m_username(username), m_user_id(GenerateUserId(username))
{
    // some other implementations
}


/**
 * \brief Should not be used for ANYTHING other then Backend/SqlDatabase
 */
export __declspec(dllexport) struct UserStructModel
{
    std::string m_surname;
    std::string m_givenName;
    std::string m_username;
    int m_user_id;
};