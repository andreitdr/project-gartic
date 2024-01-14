#include <string>
#include <tuple>

#include <crow.h>
#include "Infrastructure/BaseResponse.h"

#include "API/Game/CreateLobby.h"
#include "API/Game/ExitGame.h"
#include "API/Game/GetDrawing.h"
#include "API/Game/GetRunningGameForUser.h"
#include "API/Game/StartGame.h"
#include "API/Game/JoinLobby.h"
#include "API/Game/LeaveLobby.h"
#include "API/Game/UpdateLobby.h"
#include "API/Game/LobbyStatus.h"
#include "API/Game/JoinRandomLobby.h"
#include "API/Game/SendDrawing.h"

#include "API/Game/GetRunningGameStatus.h"
#include "API/Game/CheckWord.h"
#include "API/Game/GetChatMessages.h"

#include "API/User/GetUserInfo.h"
#include "API/User/UserLogin.h"
#include "API/User/UserRegistration.h"
#include "API/User/GetUserMatchHistoryData.h"
#include "GameManagement/GameManager.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/game/get_chat_messages").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");
            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetChatMessages(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/check_word").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");
            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = CheckWord(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/get_running_game_status").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");
            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetRunningGameStatus(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/user/match_history_data").methods("GET"_method)([] (const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetUserMatchHistoryData(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/lobby_status").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetLobbyStatus(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/join_lobby").methods("POST"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = JoinLobby(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/leave_lobby").methods("POST"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = LeaveLobby(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/update_lobby").methods("POST"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = UpdateLobby(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/join_random_lobby").methods("POST"_method)([](const crow::request& request)
        {
            const auto json = crow::json::load(request.body);
            if (!json)
            {
                BaseResponse response;
                response.m_successState = false;
                response.AppendMessage("The json was in an incorrect format");

                auto responseJson = JsonConvertor::ConvertBaseResponse(response);
                return crow::response(responseJson);
            }

            auto response = JoinRandomLobby(json);
            return crow::response(response);
        });

    CROW_ROUTE(app, "/user/get_user").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);
        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetUserInfo(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/create_game").methods("POST"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = StartGame(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/create_lobby").methods("POST"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = CreateLobby(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/user/register").methods("POST"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = (RegisterUser(json));
        return crow::response(response);
    });

    CROW_ROUTE(app, "/user/login").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }
        
        auto wjson = UserLogin(json);
        return crow::response(wjson);
    });

    CROW_ROUTE(app, "/game/get_game_for_user").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetRunningGameForUser(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/exit_game").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = ExitGame(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/send_drawing").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = SendDrawing(json);
        return crow::response(response);
    });

    CROW_ROUTE(app, "/game/get_drawing").methods("GET"_method)([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("The json was in an incorrect format");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }

        auto response = GetDrawing(json);
        return crow::response(response);
    });

    app.loglevel(crow::LogLevel::Debug);
    app.port(18080).multithreaded().run();

    return 0;
}
