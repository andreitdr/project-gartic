#include <map>
#include "Credentials.h"



Credentials::Credentials(const std::string& username, const std::string& nonHashedPassword)
	:m_username(username), m_hashedPassword(hashString(nonHashedPassword))
{
	
}

std::size_t Credentials::hashString(const std::string& stringToBeHashed)
{
	constexpr std::hash<std::string> _hasher;

	return _hasher(stringToBeHashed);
}