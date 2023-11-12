export module GameManager;

import <string>;
export class GameManager
{
public:
    static void SetPoints(int gameID, int userID, int points);
    static void AddPoints(int gameID, int userID, int points);
    
    static std::string GetNewWord(int gameID);
    static bool IsCorrectWord(int gameID, const std::string& word);
};