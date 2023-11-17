export module QueueManager;

import <vector>;

export import User;
export class QueueManager
{
public:
    static bool IsReady(int queueID);
    
    static void AppendUser(int userID);
    static void RemoveUser(int userID);
    
    static std::vector<User> GetWaitingList();
};