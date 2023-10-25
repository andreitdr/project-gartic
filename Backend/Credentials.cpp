#include "Credentials.h"

Credentials::Credentials(const std::string& username, const std::string& nonHashedPassword)
	:m_username(username)
{

}


std::string hashString(const std::string& stringToBeHashed)
{
	// hash the input string
}