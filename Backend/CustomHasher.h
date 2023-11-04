#pragma once
#include <string>
class CustomHasher
{
private:
	static std::string generateHashStringWithKey(const std::string& inputString, const size_t key);

public:
	static std::string hashString(const std::string& inputString);
};

