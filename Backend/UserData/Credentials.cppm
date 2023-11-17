export module Credentials;
import <string>;


export struct credentials
{
    std::string m_username;
    std::string m_hashedPassword;
};

export class Credentials
{
public:
    std::string m_username;
    std::string m_password;
    
};
