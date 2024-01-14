#include "SqlDatabase.h"

#include "../Constants.h"


inline Storage storage{ CreateDatabase(configFile.ReadValue("DatabaseName")) };
//inline Storage storage{ CreateDatabase("test.db") };
SqlDatabase::SqlDatabase()
{
    storage.sync_schema();
}
