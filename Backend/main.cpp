import User;
#include <crow.h>
#include "API/User/UserRegistration.h"
#include "API/User/UserLogin.h"
#include "Constants.h"
#include "SqlDatabase/SqlDatabase.h"

int main()
{
    SqlDatabase::Init();
    crow::SimpleApp app;

    k_logger.LogMessage("Starting server...", "main.cpp");

    CROW_ROUTE(app, "/user/register")
    .methods("POST"_method)
    ([](const crow::request& request){
        auto json = crow::json::load(request.body);
        
        if(!json)
            return K_CROW_ERROR_INVALID_JSON;
        
        auto response =  (RegisterUser(json));
        return crow::response(response);
    });
    
    CROW_ROUTE(app, "/user/login")
    .methods("POST"_method)
    ([](const crow::request& request)
    {
       auto json = crow::json::load(request.body);

        if(!json)
            return K_CROW_ERROR_INVALID_JSON;
        
        return crow::response(UserLogin(json));
    });
    
    app.loglevel(crow::LogLevel::Error);
    app.port(18080).multithreaded().run();
    return 0;
}
