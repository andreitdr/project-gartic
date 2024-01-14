#include "SqlDatabase.h"

#include "../Constants.h"

inline Storage storage{ CreateDatabase(configFile.ReadConfig("DatabaseName")) };

SqlDatabase::SqlDatabase()
{
    storage.sync_schema();
}
