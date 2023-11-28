export module StartGameResponse;
import <string>;
import <vector>;

#include <cstdint>


export import BaseResponse;


export class StartGameResponse : public BaseResponse
{
public:
    StartGameResponse(int gameID, const std::vector<std::string>& words);
    StartGameResponse(const std::string& message);

    
    int GetGameID() const;
    std::vector<std::string> GetWords() const;

    void AppendWord(const std::string& words);

private:
    std::vector<std::string> m_words;
    int m_gameID;
};

StartGameResponse::StartGameResponse(const std::string& message) : BaseResponse()
{
    m_successState = false;
    AppendMessage(message);
}

StartGameResponse::StartGameResponse(int gameID, const std::vector<std::string>& words) : m_gameID{gameID}, m_words{words}
{
    BaseResponse::m_successState = true;
}

int StartGameResponse::GetGameID() const
{
    return m_gameID;
}

std::vector<std::string> StartGameResponse::GetWords() const
{
    return m_words;
}

void StartGameResponse::AppendWord(const std::string& word)
{
    m_words.push_back(word);
}

