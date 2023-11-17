export module Credentials;
import <string>;


export __declspec(dllexport) struct credentials
{
    std::string m_username;
    std::string m_hashedPassword;
};

export __declspec(dllexport) class Credentials
{
public:
    std::string m_username;
    std::string m_password;
    
};
