﻿#pragma once
#include "../../Utils/JsonConvertor.h"
#include "../../SqlDatabase/SqlDatabase.h"
#include "../BaseContext.h"

#include <fstream>

import StartGameRequest;
import StartGameResponse;

class StartGameContext final : public BaseContext<StartGameRequest, StartGameResponse>
{

public:
    StartGameResponse HandleRequest(const StartGameRequest& request) override;

private:
    StartGameResponse ApplyChanges(const StartGameRequest& request) override;
    std::vector<std::string> GenerateWords(size_t count);
};

StartGameResponse StartGameContext::HandleRequest(const StartGameRequest& request)
{
    // TODO: Validate data
    return ApplyChanges(request);
}

inline StartGameResponse StartGameContext::ApplyChanges(const StartGameRequest& request)
{
    try
    {
        RunningGame running_game = RunningGame();
        running_game.m_gameId = -1;

        auto users = request.GetUsers();
        
        std::vector<std::string> wordsGenerated = GenerateWords(users.size());
        running_game.m_gameWords = JsonConvertor::ConvertFromVector<std::string>(wordsGenerated).dump();
        running_game.m_userIds = JsonConvertor::ConvertFromVector<int>(users).dump();
        
        int gameID = SqlDatabase::Insert(running_game);
        
        StartGameResponse response = StartGameResponse(gameID, wordsGenerated);
        return response;
    }
    catch (const std::exception& e)
    {
        return StartGameResponse(e.what());
    }
}

std::vector<std::string> StartGameContext::GenerateWords(size_t count)
{
    std::vector<std::string> words = {};
    std::vector<std::string> lines;
    
    std::ifstream file("unique_words.txt");
    std::string line="";
    
    while(std::getline(file, line))
        lines.push_back(line);
    
    for(int i = 0; i < count; i++)
    {
        int random_line_index = std::rand() % lines.size();
        words.push_back(lines[random_line_index]);
    }

    
    return words;
}
