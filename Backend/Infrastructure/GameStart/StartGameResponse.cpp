#include "StartGameResponse.h"

StartGameResponse::StartGameResponse(const std::string& message) : BaseResponse()
{
    m_successState = false;
    AppendMessage(message);
}

StartGameResponse::StartGameResponse(int gameID, const std::vector<std::string>& words) : m_words{words},
    m_gameID{gameID}
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
