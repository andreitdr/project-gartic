#pragma once

#include <string>

namespace ApiEndpoints {
    const std::string BASE_ADDRESS = "http://localhost";
    const std::string BASE_PORT = "18080";
    const std::string BASE_URL = BASE_ADDRESS + ":" + BASE_PORT;
    const std::string REGISTER_USER = BASE_URL + "/user/register";
    const std::string LOGIN_USER = BASE_URL + "/user/login";
    const std::string GET_USER_INFO = BASE_URL + "/user/get_user";
    const std::string CREATE_LOBBY = BASE_URL + "/game/create_lobby";
    const std::string JOIN_LOBBY = BASE_URL + "/game/join_lobby";
    const std::string LEAVE_LOBBY = BASE_URL + "/game/leave_lobby";
    const std::string LOBBY_STATUS = BASE_URL + "/game/lobby_status";
    const std::string UPDATE_LOBBY = BASE_URL + "/game/update_lobby";
    const std::string JOIN_RANDOM_LOBBY = BASE_URL + "/game/join_random_lobby";
    const std::string START_GAME = BASE_URL + "/game/create_game";
    const std::string GET_RUNNING_GAME_FOR_USER = BASE_URL + "/game/get_game_for_user";
    const std::string GET_RUNNING_GAME_STATUS = BASE_URL + "/game/get_running_game_status";
    const std::string GAME_SEND_DRAWING = BASE_URL + "/game/send_drawing";
    const std::string GAME_GET_DRAWING = BASE_URL + "/game/get_drawing";
    const std::string EXIT_GAME = BASE_URL + "/game/exit_game";
    const std::string GAME_CHECK_WORD = BASE_URL + "/game/check_word";
    const std::string GAME_GET_CHAT_MESSAGES = BASE_URL + "/game/get_chat_messages";
}
