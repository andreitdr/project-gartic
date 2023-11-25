#pragma once
/**
 * \brief Error message for incorrect formated JSON string
 */
import Logger;
#include <iostream>;
#define K_CROW_ERROR_INVALID_JSON crow::response(400, "The json was in an incorrect format")
#define K_CROW_ERROR_USER_NOT_FOUND crow::response(400, "The user was not found")


static Logger k_logger(std::cout,Logger::Level::Debug,"log.txt");