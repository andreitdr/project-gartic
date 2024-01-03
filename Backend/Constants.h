#pragma once
#include <iostream>
import Logger;

static Logger k_logger(std::cout, Logger::Level::Debug, "log.txt");
