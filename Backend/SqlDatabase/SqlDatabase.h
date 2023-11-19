#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>
#include "../Constants.h"

import User;
import Credentials;

inline auto CreateDatabase(const std::string& fileName)
{
    return sqlite_orm::make_storage(fileName,
        sqlite_orm::make_table("Users",
            sqlite_orm::make_column("Id", &UserStructModel::m_user_id, sqlite_orm::primary_key().autoincrement()),
            sqlite_orm::make_column("Username", &UserStructModel::m_username),
            sqlite_orm::make_column("Surname", &UserStructModel::m_surname),
            sqlite_orm::make_column("GivenName", &UserStructModel::m_givenName)),
        sqlite_orm::make_table("Credentials",
            sqlite_orm::make_column("Username", &Credentials::m_username),
            sqlite_orm::make_column("Password", &Credentials::m_hashedPassword))
    );
}

using Storage = decltype(CreateDatabase(""));
inline Storage storage{ CreateDatabase("test.db") };

class SqlDatabase
{
public:
    static void Init();
    
    template <typename TypeAsStruct>
    static int Insert(const TypeAsStruct& model);

    template <typename TypeAsStruct>
    static TypeAsStruct Get(int id);
    
    template <typename  TypeAsStruct>
    TypeAsStruct Get(sqlite_orm::internal::where_t<TypeAsStruct> whereClause);
    
    template <typename TypeAsStruct>
    static bool Exists( auto whereClause);

    template <typename TypeAsStruct>
    static bool ExistsModel(const TypeAsStruct& model);

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
TypeAsStruct SqlDatabase::Get( sqlite_orm::internal::where_t<TypeAsStruct> whereClause)
{
    k_logger.LogMessage(std::format("Getting {}",typeid(TypeAsStruct).name()));
    return storage.get<TypeAsStruct>(whereClause);
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

