#include "RunningGame.h"

RunningGame::RunningGame(int gameId, const std::vector<int>& playerIds, const std::vector<std::string>& words)
	: m_gameId(gameId), m_playerIds(playerIds), m_gameWords(std::queue<std::string>(words.begin(), words.end())) {}

RunningGame::RunningGame(const RunningGame& other) : m_gameId(other.m_gameId), m_indexPlayerDrawing(other.m_indexPlayerDrawing),
	m_currentRound(other.m_currentRound), m_timer(other.m_timer), m_drawing(other.m_drawing), m_playerPoints(other.m_playerPoints),
	m_guessTimes(other.m_guessTimes), m_playerIds(other.m_playerIds), m_chatMessages(other.m_chatMessages), m_gameWords(other.m_gameWords) {}

RunningGame::RunningGame(RunningGame&& other) noexcept : m_gameId(other.m_gameId), m_indexPlayerDrawing(other.m_indexPlayerDrawing),
	m_currentRound(other.m_currentRound), m_timer(other.m_timer), m_drawing(other.m_drawing), m_playerPoints(other.m_playerPoints),
	m_guessTimes(other.m_guessTimes), m_playerIds(other.m_playerIds), m_chatMessages(other.m_chatMessages), m_gameWords(other.m_gameWords)
{
}

RunningGame& RunningGame::operator=(const RunningGame& other)
{
		if (this == &other)
		return *this;

	m_gameId = other.m_gameId;
	m_indexPlayerDrawing = other.m_indexPlayerDrawing;
	m_currentRound = other.m_currentRound;
	m_timer = other.m_timer;
	m_drawing = other.m_drawing;
	m_playerPoints = other.m_playerPoints;
	m_guessTimes = other.m_guessTimes;
	m_playerIds = other.m_playerIds;
	m_chatMessages = other.m_chatMessages;
	m_gameWords = other.m_gameWords;

	return *this;
}