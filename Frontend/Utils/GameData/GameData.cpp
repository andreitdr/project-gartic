#include "GameData.h"
#include <algorithm>
#include <ranges>

GameData::GameData() : m_gameId(0), m_currentRound(0), m_timer(0) {}

GameData::~GameData() {}

GameData::GameData(const GameData& other) :
    m_gameId(other.m_gameId),
    m_players(other.m_players),
    m_playerPoints(other.m_playerPoints),
    m_drawingPlayer(other.m_drawingPlayer),
    m_drawing(other.m_drawing),
    m_currentRound(other.m_currentRound),
    m_timer(other.m_timer),
    m_currentWord(other.m_currentWord),
    m_chatMessages(other.m_chatMessages) {}

GameData& GameData::operator=(const GameData& other) {
    if (this != &other) {
        m_gameId = other.m_gameId;
        m_players = other.m_players;
        m_playerPoints = other.m_playerPoints;
        m_drawingPlayer = other.m_drawingPlayer;
        m_drawing = other.m_drawing;
        m_currentRound = other.m_currentRound;
        m_timer = other.m_timer;
        m_currentWord = other.m_currentWord;
        m_chatMessages = other.m_chatMessages;
    }
    return *this;
}

GameData::GameData(GameData&& other) noexcept :
    m_gameId(other.m_gameId),
    m_players(std::move(other.m_players)),
    m_playerPoints(std::move(other.m_playerPoints)),
    m_drawingPlayer(std::move(other.m_drawingPlayer)),
    m_drawing(std::move(other.m_drawing)),
    m_currentRound(other.m_currentRound),
    m_timer(other.m_timer),
    m_currentWord(std::move(other.m_currentWord)),
    m_chatMessages(std::move(other.m_chatMessages)) {}

GameData& GameData::operator=(GameData&& other) noexcept {
    if (this != &other) {
        m_gameId = other.m_gameId;
        m_players = std::move(other.m_players);
        m_playerPoints = std::move(other.m_playerPoints);
        m_drawingPlayer = std::move(other.m_drawingPlayer);
        m_drawing = std::move(other.m_drawing);
        m_currentRound = other.m_currentRound;
        m_timer = other.m_timer;
        m_currentWord = std::move(other.m_currentWord);
        m_chatMessages = std::move(other.m_chatMessages);
    }
    return *this;
}

bool GameData::operator==(const GameData& other) const {
    if (m_gameId != other.m_gameId ||
        m_drawingPlayer.getUserId() != other.m_drawingPlayer.getUserId() ||
        m_drawing != other.m_drawing ||
        m_currentRound != other.m_currentRound ||
        m_timer != other.m_timer ||
        m_currentWord != other.m_currentWord ||
        m_players.size() != other.m_players.size() ||
        m_chatMessages.size() != other.m_chatMessages.size() ||
        m_playerPoints.size() != other.m_playerPoints.size()) {
        return false;
    }

    for (size_t i = 0; i < m_players.size(); ++i) {
        if (m_players[i].getUserId() != other.m_players[i].getUserId()) {
            return false;
        }
    }

    for (size_t i = 0; i < m_chatMessages.size(); ++i) {
        if (m_chatMessages[i] != other.m_chatMessages[i]) {
            return false;
        }
    }

    for (const auto& pair : m_playerPoints) {
        auto it = other.m_playerPoints.find(pair.first);
        if (it == other.m_playerPoints.end() || it->second != pair.second) {
            return false;
        }
    }

    return true;
}

void GameData::SetGameId(int gameId) {
    m_gameId = gameId;
}

int GameData::GetGameId() const {
    return m_gameId;
}

void GameData::AddPlayer(const UserInfo& user) {
    m_players.push_back(user);
}

void GameData::RemovePlayer(const UserInfo& user) {
    m_players.erase(std::remove_if(m_players.begin(), m_players.end(),
        [&user](const UserInfo& u) { return u.getUserId() == user.getUserId(); }),
        m_players.end());
}

std::vector<UserInfo> GameData::GetPlayers() const {
    return m_players;
}

void GameData::SetPlayers(const std::vector<UserInfo>& players)
{
    m_players = std::move(players);
}

void GameData::SetPlayerPoints(int playerId, int points) {
    m_playerPoints[playerId] = points;
}

void GameData::SetPlayerPoints(const std::unordered_map<int, int>& playerPoints)
{
    m_playerPoints = std::move(playerPoints);
}

int GameData::GetPlayerPoints(int playerId) const {
    auto it = m_playerPoints.find(playerId);
    if (it != m_playerPoints.end()) {
        return it->second;
    }
    return 0; 
}

std::unordered_map<int, int> GameData::GetPlayerPoints() const
{
    return m_playerPoints;
}

void GameData::SetDrawingPlayer(const UserInfo& user) {
    m_drawingPlayer = user;
}

UserInfo GameData::GetDrawingPlayer() const {
    return m_drawingPlayer;
}

void GameData::SetDrawing(const std::string& drawing) {
    m_drawing = drawing;
}

std::string GameData::GetDrawing() const {
    return m_drawing;
}

void GameData::SetCurrentRound(int round) {
    m_currentRound = round;
}

int GameData::GetCurrentRound() const {
    return m_currentRound;
}

void GameData::SetTimer(int timer) {
    m_timer = timer;
}

int GameData::GetTimer() const {
    return m_timer;
}

void GameData::SetCurrentWord(const std::string& word) {
    m_currentWord = word;
}

std::string GameData::GetCurrentWord() const {
    return m_currentWord;
}

void GameData::AddChatMessage(const std::string& message) {
    m_chatMessages.push_back(message);
}

std::vector<std::string> GameData::GetChatMessages() const {
    return m_chatMessages;
}
void GameData::SetChatMessages(const std::vector<std::string>& chatMessages)
{
    m_chatMessages = std::move(chatMessages);
}

void GameData::SortPlayersByPoints()
{
    std::ranges::sort(m_players, [this](const UserInfo& a, const UserInfo& b) {
        return m_playerPoints[a.getUserId()] > m_playerPoints[b.getUserId()];
        });
}
