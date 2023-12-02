import User;
import Config;
#include <crow.h>
#include "API/User/UserRegistration.h"
#include "API/User/UserLogin.h"
#include "Constants.h"
#include "API/Game/StartGame.h"
#include "API/Game/CreateLobby.h"
#include "SqlDatabase/SqlDatabase.h"
#define ENABLETEST 0

using namespace sqlite_orm;

void tests()
{
    ConfigFile config_file("./test.ini");
    config_file.WriteConfig("key1","value");
    config_file.WriteConfig("key1","value2");
    config_file.WriteConfig("key2","value3");
    std::cout<<config_file.ReadConfig("key3");
}

int main()
{
#if ENABLETEST
    tests();
#else
    
    SqlDatabase::Init();
    crow::SimpleApp app;

    k_logger.LogMessage("Starting server...", "main.cpp");

    CROW_ROUTE(app, "/game/create_game")
        .methods("POST"_method)
    ([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
            return K_CROW_ERROR_INVALID_JSON;

        auto response = StartGame(json);
        return crow::response(response);   
    });

    CROW_ROUTE(app, "/game/create_lobby")
        .methods("GET"_method)
    ([](const crow::request& request)
    {
        const auto json = crow::json::load(request.body);

        if (!json)
            return K_CROW_ERROR_INVALID_JSON;

        auto response = CreateLobby(json);
        return crow::response(response);   
    });

    CROW_ROUTE(app, "/user/register")
    .methods("POST"_method)
    ([](const crow::request& request){
        const auto json = crow::json::load(request.body);
        
        if(!json)
            return K_CROW_ERROR_INVALID_JSON;
        
        auto response =  (RegisterUser(json));
        return crow::response(response);
    });
    
    CROW_ROUTE(app, "/user/login")
    .methods("POST"_method)
    ([](const crow::request& request)
    {
       const auto json = crow::json::load(request.body);

        if(!json)
            return K_CROW_ERROR_INVALID_JSON;

        std::string username = json["username"].s();

        auto users = SqlDatabase::GetAll<User>(where(c(&User::m_username) == username));
        if(users.empty())
            return K_CROW_ERROR_USER_NOT_FOUND;

        
        auto wjson =UserLogin(json);

        wjson["UserData"] = JsonConvertor::ConvertUser(users[0], true);
        
        return crow::response(wjson);
    });
    
    app.loglevel(crow::LogLevel::Error);
    app.port(18080).multithreaded().run();
#endif
    
    return 0;
    
}
