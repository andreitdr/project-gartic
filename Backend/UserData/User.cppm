export module User;

import <string>;

/**
 * \brief Should not be used for ANYTHING other then Backend/SqlDatabase
 */
export struct User
{
    std::string m_surname;
    std::string m_givenName;
    std::string m_username;
    int m_user_id;
};