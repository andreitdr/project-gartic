#pragma once
import Logger;
#include <iostream>


static Logger k_logger(std::cout, Logger::Level::Debug, "log.txt");
