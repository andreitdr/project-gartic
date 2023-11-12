export module Credentials;
#include <string>


export struct credentials
{
    std::string m_username;
    std::string m_hashedPassword;
};
