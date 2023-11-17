#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>
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
            sqlite_orm::make_column("Username", &credentials::m_username),
            sqlite_orm::make_column("Password", &credentials::m_hashedPassword))
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
};

template <typename TypeAsStruct>
int SqlDatabase::Insert(const TypeAsStruct& model)
{
    int id = storage.insert(model);
    return id;
}

