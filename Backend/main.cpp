#include <string>
#include <tuple>

#include <crow.h>
#include "SqlDatabase/SqlDatabase.h"
#include "Infrastructure/BaseResponse.h"

#include "API/Game/CreateLobby.h"
#include "API/Game/StartGame.h"
#include "API/Game/JoinLobby.h"
#include "API/Game/LeaveLobby.h"
#include "API/Game/UpdateLobby.h"
#include "API/Game/LobbyStatus.h"

#include "API/User/GetUserInfo.h"
#include "API/User/UserLogin.h"
#include "API/User/UserRegistration.h"

#define ENABLETEST 0

using namespace sqlite_orm;

void tests()
{
    // ConfigFile config_file("./test.ini");
    // config_file.WriteConfig("key1", "value");
    // config_file.WriteConfig("key1", "value2");
    // config_file.WriteConfig("key2", "value3");
    // std::cout << config_file.ReadConfig("key3");
}

int main()
{
#if ENABLETEST
    tests();
#else

    SqlDatabase::Init();
    crow::SimpleApp app;

    k_logger.LogMessage("Starting server...", "MAIN");

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

    /*
     *  Test route. Will be removed later.
     */
    CROW_ROUTE(app, "/<int>").methods("GET"_method)([](const int v)
    {
        const auto result = SqlDatabase::Select<std::tuple<std::string, std::string>>(
            sqlite_orm::columns(&User::m_surname, &User::m_givenName), WHERE(User::m_user_id, v));
        auto user1 = result[0];

        return (std::format("surname: {}, givenName: {}", std::get<0>(user1), std::get<1>(user1)));
    });

    CROW_ROUTE(app, "/test").methods("GET"_method)([](const crow::request& request)
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

        return crow::response(1000, "Your Json is: " + crow::json::wvalue(json).dump());
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

        std::string username = json["username"].s();

        auto users = SqlDatabase::GetAll<User>(where(c(&User::m_username) == username));
        if (users.empty())
        {
            BaseResponse response;
            response.m_successState = false;
            response.AppendMessage("Inexistent user");

            auto responseJson = JsonConvertor::ConvertBaseResponse(response);
            return crow::response(responseJson);
        }


        auto wjson = UserLogin(json);

        wjson["UserData"] = JsonConvertor::ConvertUser(users[0], true);

        return crow::response(wjson);
    });

    app.loglevel(crow::LogLevel::Error);
    k_logger.LogMessage("Server is running at http://localhost:18080", "MAIN");
    app.port(18080).multithreaded().run();
#endif

    return 0;
}
