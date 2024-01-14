#include "SqlDatabase.h"



inline Storage storage{ CreateDatabase("test.db") };
//inline Storage storage{ CreateDatabase("test.db") };
SqlDatabase::SqlDatabase()
{
    storage.sync_schema();
}
