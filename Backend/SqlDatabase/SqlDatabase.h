#pragma once

#include <string>
#include <sqlite_orm/sqlite_orm.h>

#include "../DataTypes/User/User.h"
#include "../DataTypes/User/Credentials.h"
#include "../DataTypes/User/UserGameData.h"
#include "../DataTypes/Game/FinishedGame.h"
#include "../DataTypes/Game/Lobby.h"
#include "../DataTypes/Game/PlayerFinishedGame.h"


#include <optional>

//====================


/**
 * \brief WHERE macro for sqlite_orm. Checks if a field is equal to a value.
 * \param field The field to check
 * \param val The value to check against
 */
#define WHERE(field,val) sqlite_orm::where(sqlite_orm::c(&field) == val)

inline auto CreateDatabase(const std::string& fileName)
{
    return sqlite_orm::make_storage(fileName,
                                    sqlite_orm::make_table("Users",
                                                           sqlite_orm::make_column(
                                                               "Id", &User::m_user_id,
                                                               sqlite_orm::primary_key().autoincrement()),
                                                           sqlite_orm::make_column("Username", &User::m_username),
                                                           sqlite_orm::make_column("Surname", &User::m_surname),
                                                           sqlite_orm::make_column("GivenName", &User::m_givenName)),
                                    sqlite_orm::make_table("Credentials",
                                                           sqlite_orm::make_column(
                                                               "Username", &Credentials::m_username),
                                                           sqlite_orm::make_column(
                                                               "Password", &Credentials::m_hashedPassword)),
                                    sqlite_orm::make_table("UserGameData",
                                                           sqlite_orm::make_column(
                                                               "GamesPlayed", &UserGameData::m_gamesPlayed),
                                                           sqlite_orm::make_column(
                                                               "PlayerLevel", &UserGameData::m_playerLevel),
                                                           sqlite_orm::make_column(
                                                               "PlayerCurrentExp", &UserGameData::m_playerCurrentExp)),
                                    sqlite_orm::make_table("FinishedGames",
                                                           sqlite_orm::make_column(
                                                               "Id", &FinishedGame::m_gameId,
                                                               sqlite_orm::primary_key().autoincrement()),
                                                           sqlite_orm::make_column(
                                                               "GameDuration", &FinishedGame::m_gameDuration),
                                                           sqlite_orm::make_column(
                                                               "GameWords", &FinishedGame::m_gameWords)),
                                    sqlite_orm::make_table("PlayerFinishedGame",
                                        sqlite_orm::make_column("Id", &PlayerFinishedGame::m_index, sqlite_orm::primary_key().autoincrement()),
                                                           sqlite_orm::make_column("PlayerId", &PlayerFinishedGame::m_userId),
                                                           sqlite_orm::make_column("GameId", &PlayerFinishedGame::m_gameId),
                                                           sqlite_orm::make_column("PointsEarned", &PlayerFinishedGame::m_pointsEarned)),
                                    sqlite_orm::make_table("Lobbies",
                                                           sqlite_orm::make_column(
                                                               "Index", &Lobby::m_index, sqlite_orm::primary_key()),
                                                           sqlite_orm::make_column(
                                                               "LobbyId", &Lobby::m_lobbyId, sqlite_orm::unique()),
                                                           sqlite_orm::make_column("Leader", &Lobby::m_leaderId),
                                                           sqlite_orm::make_column("UserIds", &Lobby::m_userIds),
                                                           sqlite_orm::make_column("LobbyType", &Lobby::m_lobbyType),
                                                           sqlite_orm::make_column(
                                                               "IsPrivateLobby", &Lobby::m_isPrivate)));
}

using Storage = decltype(CreateDatabase(""));
inline Storage storage{CreateDatabase("test.db")};

class SqlDatabase
{
public:

    static SqlDatabase& GetInstance()
    {
        static SqlDatabase instance;
        return instance;
    }
    
    template <typename TypeAsStruct>
    int Insert(const TypeAsStruct& model);

    template <typename TypeAsStruct>
    TypeAsStruct Get(int id);

    template <typename TypeAsStruct>
     TypeAsStruct Get(auto whereCondition);

    template <typename TupleElements>
     std::vector<TupleElements> Select(auto columnsTuple, auto whereCondition);

    template <typename TypeAsStruct>
     std::vector<TypeAsStruct> GetAll(auto whereClause);

    template <typename TypeAsStruct, typename Field>
     std::optional<TypeAsStruct> GetByProperty(const Field& value, const std::string& propertyName);

    template <typename TypeAsStruct>
     bool Exists(auto whereClause);

    template <typename TypeAsStruct>
     bool Exists(int id);

    template <typename TypeAsStruct>
     bool ExistsModel(const TypeAsStruct& model);

    template <typename TypeAsStruct>
     bool Update(const TypeAsStruct& model);

    template <typename TypeAsStruct>
     bool Delete(int id);

    void operator=(const SqlDatabase&) = delete;
    SqlDatabase(const SqlDatabase&) = delete;

private:
    SqlDatabase();
    
    
};

template <typename TypeAsStruct>
int SqlDatabase::Insert(const TypeAsStruct& model)
{
   // k_logger.LogMessage(std::format("Inserting {}", typeid(model).name()));
    int id = storage.insert(model);
   // k_logger.LogMessage("Success");
    return id;
}

template <typename TypeAsStruct>
TypeAsStruct SqlDatabase::Get(int id)
{
  //  k_logger.LogMessage(std::format("Getting {} with id {}", typeid(TypeAsStruct).name(), id));
    try
    {
        return storage.get<TypeAsStruct>(id);
    }
    catch (const std::exception& err)
    {
  //      k_logger.LogError(err);
        throw err;
    }
}

template <typename TypeAsStruct>
std::vector<TypeAsStruct> SqlDatabase::GetAll(auto whereClause)
{
    return storage.get_all<TypeAsStruct>(whereClause);
}

template <typename TypeAsStruct>
TypeAsStruct SqlDatabase::Get(auto whereCondition)
{
    return GetAll<TypeAsStruct>(whereCondition)[0];
}

template <typename TupleElements>
std::vector<TupleElements> SqlDatabase::Select(auto columnsTuple, auto whereCondition)
{
    auto selectStatement = storage.prepare(sqlite_orm::select(columnsTuple, whereCondition));
//k_logger.LogMessage(selectStatement.sql(), "SQL");
    return storage.execute(selectStatement);
}


template <typename TypeAsStruct, typename Field>
std::optional<TypeAsStruct> SqlDatabase::GetByProperty(const Field& value, const std::string& propertyName)
{
    auto whereClause = sqlite_orm::where(sqlite_orm::c(propertyName) == value);
    auto result      = storage.get_all<TypeAsStruct>(whereClause);

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
    try
    {
        auto result = storage.get_all<TypeAsStruct>(whereClause);

        return result.size() > 0;
    }
    catch (std::system_error& err)
    {
     //   k_logger.LogError(err);
        return false;
    }
}

template <typename TypeAsStruct>
bool SqlDatabase::Exists(int id)
{
    try
    {
        auto result = storage.get<TypeAsStruct>(id);
        return true;
    }
    catch (std::system_error& err)
    {
    //    k_logger.LogError(err);
        return false;
    }
}


template <typename TypeAsStruct>
bool SqlDatabase::ExistsModel(const TypeAsStruct& model)
{
    // TODO: this is not working
    // The function is not generic
    auto result = storage.get_all<TypeAsStruct>(
        sqlite_orm::where(sqlite_orm::c(&TypeAsStruct::m_username) == model.m_username));
    return result.size() > 0;
}

template <typename TypeAsStruct>
bool SqlDatabase::Update(const TypeAsStruct& model)
{
    try
    {
      //  k_logger.LogMessage(std::format("Updating {}", typeid(model).name()));
        storage.update(model);
        return true;
    }
    catch (const std::exception& ex)
    {
       // k_logger.LogError(ex);
        return false;
    }
}

template <typename TypeAsStruct>
bool SqlDatabase::Delete(int id)
{
    try
    {
       // k_logger.LogMessage(std::format("Deleting {}", typeid(TypeAsStruct).name()));
        storage.remove<TypeAsStruct>(id);
        return true;
    }
    catch (const std::exception& ex)
    {
      //  k_logger.LogError(ex);
        return false;
    }
}
