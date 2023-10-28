#pragma once
#include <string>
class CustomHasher
{
private:
	std::string generateHashStringWithKey(const std::string& inputString, const size_t key);

public:
	std::string hashString(const std::string& inputString);
};

