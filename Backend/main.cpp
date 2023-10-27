#include <string>
#include <iostream>
#include "CustomHasher.h"
int main(int argc, char** argv)
{
	if (argc == 1) return 0;

	std::string inputArgument = argv[1];

	CustomHasher hasher;
	
	std::cout << hasher.hashString(inputArgument);

	return 0;
}