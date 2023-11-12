export module HistoryManager;
import <vector>;
import <string>;

export class HistoryManager
{
public:
    // Auto should be replaced when we will have a History Game class.
    static auto GetGameById(int gameID);
    static int GetWinner(int gameID);

    static std::vector<std::string> GetListOfUsedWords(int gameID);
};