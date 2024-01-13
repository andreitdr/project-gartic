#include "StartGameContext.h"
#include "../../GameManagement/GameManager.h"
#include "../../Utils/JsonConvertor.h"
#include "../../SqlDatabase/SqlDatabase.h"

#include <string>
#include <vector>
#include <random>

StartGameResponse StartGameContext::HandleRequest(const StartGameRequest& request)
{
    const int id = request.GetLobbyId();
    if (id < 0)
    {
        return StartGameResponse("Invalid lobby id");
    }

    if (!SqlDatabase::GetInstance().Exists<Lobby>(WHERE(Lobby::m_lobbyId, id)))
        return StartGameResponse("Lobby does not exist");

    
    return ApplyChanges(request);

    
}

StartGameResponse StartGameContext::ApplyChanges(const StartGameRequest& request)
{
    const int lobbyId = request.GetLobbyId();

    const Lobby lobby = SqlDatabase::GetInstance().Get<Lobby>(WHERE(Lobby::m_lobbyId, lobbyId));

    const std::vector<int> playerIds              = JsonConvertor::ConvertToVector<int>(lobby.m_userIds);
    const std::vector<std::string> generatedWords = GenerateWords(playerIds.size() * GameManager::k_defaultNumberOfCycles);
    const int gameId                              = GameManager::GetInstance().CreateGame(playerIds, generatedWords);

    return StartGameResponse(gameId);
}

std::vector<std::string> StartGameContext::GenerateWords(size_t count)
{
    std::vector<std::string> words = {};
    std::vector<std::string> lines;

    std::ifstream file("unique_words.txt");
    std::string line = "";

    while (std::getline(file, line)) lines.push_back(line);

    for (int i = 0; i < count; i++)
    {
        const int random_line_index = std::rand() % lines.size();
        words.push_back(lines[random_line_index]);
    }


    return words;
}