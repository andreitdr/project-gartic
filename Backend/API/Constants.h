#pragma once
/**
 * \brief Error message for incorrect formated JSON string
 */
#define K_CROW_ERROR_INVALID_JSON crow::response(400, "The json was in an incorrect format")