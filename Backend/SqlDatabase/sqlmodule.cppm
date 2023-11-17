export module sqlmodule;
#include <sqlite_orm/sqlite_orm.h>


namespace sql = sqlite_orm;

import <filesystem>;
import <memory>;
export import User;
export import Credentials;

inline auto CreateStorage(const std::string& fileName)
{
    return sql::make_storage(fileName,
                             sql::make_table("Users",
                                             sql::make_column("Id", &UserStructModel::m_user_id,
                                                              sql::primary_key().autoincrement()),
                                             sql::make_column("Username", &UserStructModel::m_username),
                                             sql::make_column("Surname", &UserStructModel::m_surname),
                                             sql::make_column("GivenName", &UserStructModel::m_givenName)
                             ),
                             sql::make_table("Credentials",
                                             sql::make_column("Username", &credentials::m_username),
                                             sql::make_column("Password", &credentials::m_hashedPassword)
                             ));
}

export using Storage = decltype(CreateStorage(""));
static Storage storage = CreateStorage("test.db");

export class SqlDatabase
{
public:
    static int Insert(const UserStructModel& data);
    
    static UserStructModel Get(int objectID);

};

int SqlDatabase::Insert(const UserStructModel& data)
{
    return storage.insert<UserStructModel>(data);
}
