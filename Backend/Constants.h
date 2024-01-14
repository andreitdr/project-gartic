#pragma once

import Config;
import Logger;

inline ConfigFile configFile{ "backend.data" };
inline Logger k_logger(std::cout, Logger::Level::Debug, "logs.txt");