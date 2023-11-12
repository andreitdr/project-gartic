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
    static SqlDatabase GetDatabase(const std::string& fileName);
    static SqlDatabase GetDatabase();

    template<typename StructType>
    bool RecordExists(StructType like);

    template<typename StructType>
    int Insert(StructType object);
    

    std::string ExecuteQuery(const std::string& query, const std::string&... params);
    
private:
    static SqlDatabase k_runningDatabse;

    
    std::string m_filePath;
    internal::storage_t<auto> m_databaseStorage;
    bool m_isInitialized;
    
    SqlDatabase(const std::string& fileLocation);
};


template <typename T>
bool SqlDatabase::RecordExists(T like)
{
    if(auto record = m_databaseStorage.get<T>(like))
        return true;

    return false;
}

template <typename StructType>
int SqlDatabase::Insert(StructType object)
{
    return m_databaseStorage.insert<StructType>(object);
}

SqlDatabase::SqlDatabase(const std::string& fileLocation) : m_filePath(fileLocation)
{
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
    this->m_isInitialized = true;
    
}

SqlDatabase SqlDatabase::GetDatabase(const std::string& fileName)
{
    try
    {
        if(k_runningDatabse.m_isInitialized)
            return k_runningDatabse;
    }catch(...)
    {
        // logs...
    }

    return SqlDatabase(fileName);
}

SqlDatabase SqlDatabase::GetDatabase()
{
    try
    {
        if(k_runningDatabse.m_isInitialized)
            return k_runningDatabse;
        
    }catch(const std::exception& e)
    {
        throw e;
    }

    throw std::exception("Expected filePath");
}

std::string SqlDatabase::ExecuteQuery(const std::string& query, const std::string&... params)
{
    return std::string("");
}


