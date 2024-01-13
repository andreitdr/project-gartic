#include "SqlDatabase.h"


SqlDatabase::SqlDatabase()
{
    storage.sync_schema();
}
