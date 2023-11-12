export module UserManager;

import <vector>;
export import User;
export class UserManager
{
public:
    static User GetUser(int userID);
    static std::vector<int> GetMatchHistory();

    
};