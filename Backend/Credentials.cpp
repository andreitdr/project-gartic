#include "Credentials.h"
#include "CustomHasher.h"


Credentials::Credentials(const std::string& username, const std::string& nonHashedPassword)
	:m_username(username), m_nonHashedPassword(hashString(nonHashedPassword))
{
	
}

std::string Credentials::hashString(const std::string& stringToBeHashed)
{
	return CustomHasher :: hashString(stringToBeHashed);
}

const std::string Credentials::getNonHashedPassword() const
{
	return m_nonHashedPassword;
}

