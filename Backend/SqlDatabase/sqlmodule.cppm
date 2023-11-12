export module sqlmodule;
#include <filesystem>
#include <string>

import Credentials;
import User;

import <sqlite_orm/sqlite_orm.h>;

using namespace sqlite_orm;

export class SqlDatabase
{
public:
    SqlDatabase(const std::string& fileLocation);
    std::string ExecuteQuery(const std::string& sqlQuery, const std::string&... args);
private:
    std::string m_filePath;
    internal::storage_t<auto> m_databaseStorage;
};


SqlDatabase::SqlDatabase(const std::string& fileLocation) : m_filePath(fileLocation)
{
    if(std::filesystem::exists(fileLocation)) return;

    auto storage = make_storage(fileLocation,
        make_table("Users",
            make_column("Id", &UserStructModel::m_user_id, primary_key().autoincrement()),
            make_column("Username", &UserStructModel::m_username),
            make_column("Surname", &UserStructModel::m_surname),
            make_column("GivenName", &UserStructModel::m_givenName)
            ),
        make_table("Credentials",
            make_column("Username", &credentials::m_username),
            make_column("Password", &credentials::m_hashedPassword)
        )
    );

    this->m_databaseStorage = storage;
    
}

std::string SqlDatabase::ExecuteQuery(const std::string& sqlQuery, const std::string&... args)
{
    return std::string();
}


