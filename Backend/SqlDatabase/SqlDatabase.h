#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>
#include "../Constants.h"

import User;
import Credentials;
import UserGameData;
import Game;

inline auto CreateDatabase(const std::string& fileName)
{
    return sqlite_orm::make_storage(fileName,
        sqlite_orm::make_table("Users",
            sqlite_orm::make_column("Id", &User::m_user_id, sqlite_orm::primary_key().autoincrement()),
            sqlite_orm::make_column("Username", &User::m_username),
            sqlite_orm::make_column("Surname", &User::m_surname),
            sqlite_orm::make_column("GivenName", &User::m_givenName)),
        sqlite_orm::make_table("Credentials",
            sqlite_orm::make_column("Username", &Credentials::m_username),
            sqlite_orm::make_column("Password", &Credentials::m_hashedPassword)),
        sqlite_orm::make_table("UserGameData",
            sqlite_orm::make_column("GamesPlayed",&UserGameData::m_gamesPlayed),
            sqlite_orm::make_column("PlayerLevel",&UserGameData::m_playerLevel),
            sqlite_orm::make_column("PlayerCurrentExp",&UserGameData::m_playerCurrentExp)),
        sqlite_orm::make_table("GamesHistory",
            sqlite_orm::make_column("Id", &Game::m_gameId, sqlite_orm::primary_key().autoincrement()),
            sqlite_orm::make_column("WinnerID", &Game::m_winnerId, sqlite_orm::foreign_key(&User::m_user_id)),
            sqlite_orm::make_column("GameDuration", &Game::m_gameDuration),
            sqlite_orm::make_column("GameWords", &Game::m_gameWords))
    );
}

using Storage = decltype(CreateDatabase(""));
static inline Storage storage{ CreateDatabase("test.db") };

class SqlDatabase
{
public:
    static void Init();
    
    template <typename TypeAsStruct>
    static int Insert(const TypeAsStruct& model);

    template <typename TypeAsStruct>
    static TypeAsStruct Get(int id);

    template<typename TypeAsStruct>
    static std::vector<TypeAsStruct> GetAll(auto whereClause);
    
    template <typename TypeAsStruct, typename Field>
    static std::optional<TypeAsStruct> GetByProperty(const Field& value, const std::string& propertyName);

    template <typename TypeAsStruct>
    static bool Exists( auto whereClause);

    template <typename TypeAsStruct>
    static bool ExistsModel(const TypeAsStruct& model);

    /*template <typename TypeAsStruct, typename Field>
    static bool ExistsModel(const TypeAsStruct& model, const Field& field);*/

    template <typename TypeAsStruct>
    static bool Update(const TypeAsStruct& model);
    
};

template <typename TypeAsStruct>
int SqlDatabase::Insert(const TypeAsStruct& model)
{
    k_logger.LogMessage(std::format("Inserting {}",typeid(model).name()));
    int id = storage.insert(model);
    k_logger.LogMessage("Success");
    return id;
}

template <typename TypeAsStruct>
TypeAsStruct SqlDatabase::Get(int id)
{
    k_logger.LogMessage(std::format("Getting {} with id {}",typeid(TypeAsStruct).name(),id));
    return storage.get<TypeAsStruct>(id);
}

template <typename TypeAsStruct>
std::vector<TypeAsStruct> SqlDatabase::GetAll(auto whereClause)
{
    return storage.get_all<TypeAsStruct>(whereClause);
}


template <typename TypeAsStruct, typename Field>
std::optional<TypeAsStruct> SqlDatabase::GetByProperty(const Field& value, const std::string& propertyName)
{
    auto whereClause = sqlite_orm::where(sqlite_orm::c(propertyName) == value);
    auto result = storage.get_all<TypeAsStruct>(whereClause);

    if (!result.empty())
    {
        return result.front();
    }
    else
    {
        return std::nullopt;
    }
}

template <typename TypeAsStruct>
bool SqlDatabase::Exists(auto whereClause)
{
    auto result_list = storage.get_all<TypeAsStruct>(whereClause);
    return result_list.size() > 0;
}

template <typename TypeAsStruct>
bool SqlDatabase::ExistsModel(const TypeAsStruct& model)
{
    // TODO: this is not working
    // The function is not generic
    auto result = storage.get_all<TypeAsStruct>(sqlite_orm::where(sqlite_orm::c(&TypeAsStruct::m_username) == model.m_username));
    return result.size() > 0;
}

//A
/*template <typename TypeAsStruct, typename Field>
bool SqlDatabase::ExistsModel(const TypeAsStruct& model, const Field& field)
{
    auto result = storage.get_all<TypeAsStruct>(sqlite_orm::where(sqlite_orm::c(field) == field(model)));
    return result.size() > 0;
}*/

//OR B; TO IMPLEMENT operator==
/*template <typename TypeAsStruct>
bool SqlDatabase::ExistsModel(const TypeAsStruct& model)
{
    auto result = storage.get_all<TypeAsStruct>(
        sqlite_orm::where([&model](const TypeAsStruct& row){
            return row == model;})
    );
    return result.size() > 0;
}*/

template <typename TypeAsStruct>
bool SqlDatabase::Update(const TypeAsStruct& model)
{
    try
    {
        k_logger.LogMessage(std::format("Updating {}",typeid(model).name()));
        storage.update(model);
        return true;
    }
    catch(const std::exception& ex)
    {
        k_logger.LogError(ex);
        return false;
    }
    
}

