import User;
#include "SqlDatabase/SqlDatabase.h"

int main()
{
 
    UserStructModel model;
    model.m_surname = "surname2";
    model.m_username = "username1";
    model.m_givenName = "givenname1";
    model.m_user_id = -1;

    SqlDatabase::Init();
    SqlDatabase::Insert<UserStructModel>(model);
    return 0;
}
