#include "CustomHasher.h"
#include <map>
std::string CustomHasher::generateHashStringWithKey(const std::string& inputString, const size_t key)
{
	int stringLength = inputString.length();
	std::string outputString = "";
	for (int index = 0; index < stringLength; ++index)
	{
		outputString += (char)((int)inputString[index] + key);
	}

	return outputString;
}
std::string CustomHasher::hashString(const std::string& inputString)
{
	std::hash<std::string> stringHasher;
	size_t generatevValue = stringHasher(inputString);
	return generateHashStringWithKey(inputString, generatevValue);
}
