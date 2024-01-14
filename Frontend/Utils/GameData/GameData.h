#pragma once
#include "../../Utils/UserInfo/UserInfo.h"
#include <vector>
#include <string>
#include <unordered_map>

class GameData
{
public:
    GameData();
    ~GameData();

    GameData(const GameData& other);
    GameData& operator=(const GameData& other);

    GameData(GameData&& other) noexcept;
    GameData& operator=(GameData&& other) noexcept;

    bool operator==(const GameData& other) const;

    void SetGameId(int gameId);
    int GetGameId() const;

    void AddPlayer(const UserInfo& user);
    void RemovePlayer(const UserInfo& user);
    std::vector<UserInfo> GetPlayers() const;
    void SetPlayers(const std::vector<UserInfo>& players);

    void SetPlayerPoints(int playerId, int points);
    void SetPlayerPoints(const std::unordered_map<int, int>& playerPoints);
    int GetPlayerPoints(int playerId) const;
    std::unordered_map<int, int> GetPlayerPoints() const;

    void SetDrawingPlayer(const UserInfo& user);
    UserInfo GetDrawingPlayer() const;

    void SetDrawing(const std::string& drawing);
    std::string GetDrawing() const;

    void SetCurrentRound(int round);
    int GetCurrentRound() const;

    void SetTimer(int timer);
    int GetTimer() const;

    void SetCurrentWord(const std::string& word);
    std::string GetCurrentWord() const;

    void AddChatMessage(const std::string& message);
    std::vector<std::string> GetChatMessages() const;
    void SetChatMessages(const std::vector<std::string>& chatMessages);

    void SortPlayersByPoints();

private:
    int m_gameId;
    std::vector<UserInfo> m_players;
    std::unordered_map<int, int> m_playerPoints;
    UserInfo m_drawingPlayer;
    std::string m_drawing;
    int m_currentRound;
    int m_timer;
    std::string m_currentWord;
    std::vector<std::string> m_chatMessages;
};
