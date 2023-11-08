#include <string>
#include <iostream>
#include "CustomHasher.h"
import infosaver;
int main(int argc, char** argv)
{

	InfoSaver::InitializeUser(1);
	std::cout << InfoSaver::GetPoints(1);
	if (argc == 1) return 0;

	std::string inputArgument = argv[1];

	InfoSaver::InitializeUser(1);
	std::cout << InfoSaver::GetPoints(1);
	std::cout << CustomHasher::hashString(inputArgument);

	return 0;
}