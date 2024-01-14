#include "SqlDatabase.h"


//inline Storage storage{ CreateDatabase(configFile.ReadConfig("DatabaseName")) };
inline Storage storage{ CreateDatabase("test.db") };
SqlDatabase::SqlDatabase()
{
    storage.sync_schema();
}
