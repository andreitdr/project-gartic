#pragma once

#include <iostream>

import Logger;

inline Logger k_logger(std::cout, Logger::Level::Debug, "logs.txt");