#pragma once
#pragma once

#include <string>

namespace ApiEndpoints {
    const std::string BASE_URL = "http://localhost:18080";
    const std::string REGISTER_USER = BASE_URL + "/user/register";
    const std::string LOGIN_USER = BASE_URL + "/user/login";
    const std::string GET_USER_INFO = BASE_URL + "/user/get_user";
    const std::string CREATE_LOBBY = BASE_URL + "/game/create_lobby";
    const std::string JOIN_LOBBY = BASE_URL + "/game/join_lobby";
    const std::string LEAVE_LOBBY = BASE_URL + "/game/leave_lobby";
    const std::string LOBBY_STATUS = BASE_URL + "/game/lobby_status";
}
