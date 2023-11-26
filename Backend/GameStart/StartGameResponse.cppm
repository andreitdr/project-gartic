export module StartGameResponse;
import <string>;
import <vector>;

#include <cstdint>


export import BaseResponse;


export class StartGameResponse : BaseResponse
{
public:
    StartGameResponse(uint32_t gameID, const std::vector<std::string>& words);
    uint32_t GetGameID() const;
    std::vector<std::string> GetWords() const;

    void AppendWord(const std::string& words);

private:
    std::vector<std::string> m_words;
    uint32_t m_gameID;
};

StartGameResponse::StartGameResponse(uint32_t gameID, const std::vector<std::string>& words) : m_gameID{gameID}, m_words{words}
{
}

uint32_t StartGameResponse::GetGameID() const
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

