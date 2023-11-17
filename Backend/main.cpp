import sqlmodule;

int main()
{
 
    UserStructModel model;
    model.m_surname = "surname1";
    model.m_username = "username1";
    model.m_givenName = "givenname1";
    model.m_user_id = -1;
    
    int id = SqlDatabase::Insert(model);
    return 0;
}