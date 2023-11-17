import User;
#include <crow.h>
#include "API/Constants.h"
#include "API/User/UserRegistration.h"
#include <iostream>

#include "SqlDatabase/SqlDatabase.h"

int main()
{

    SqlDatabase::Init();
    
    crow::SimpleApp app;

    CROW_ROUTE(app, "/user/register")
    .methods("GET"_method)
    ([](const crow::request& request){
        auto json = crow::json::load(request.body);
        std::cout << request.body;
        if(!json)
            return K_CROW_ERROR_INVALID_JSON;

        return crow::response(RegisterUser(json));
    });

    app.port(18080).multithreaded().run();
    return 0;
}
