#pragma once
#include <string>
#include <vector>

#include "../../Infrastructure/BaseResponse.h"


class StartGameResponse : public BaseResponse
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
