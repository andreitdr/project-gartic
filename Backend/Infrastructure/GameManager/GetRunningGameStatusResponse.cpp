#include "GetRunningGameStatusResponse.h"

GetRunningGameStatusResponse::GetRunningGameStatusResponse(const std::string& message) : BaseResponse(false)
{
    AppendMessage(message);
}

GetRunningGameStatusResponse::GetRunningGameStatusResponse(const std::string& message, bool success) : BaseResponse(success)
{
    AppendMessage(message);
}

GetRunningGameStatusResponse::GetRunningGameStatusResponse(bool success) : BaseResponse(success)
{
}

GetRunningGameStatusResponse::GetRunningGameStatusResponse(int drawingPlayerId, int currentRound, int timer,
    const std::string& currentWord, const std::vector<int>& playerIds, const std::unordered_map<int, int>& playerPoints)
        : BaseResponse {true}, m_playerDrawingId{drawingPlayerId},  m_currrentRound {currentRound}, m_timer {timer}, m_currentWord {currentWord},
        m_playerIds {playerIds}, m_playerPoints {playerPoints}
{
}

int GetRunningGameStatusResponse::GetPlayerDrawingId() const
{
    return m_playerDrawingId;
}

int GetRunningGameStatusResponse::GetCurrentRound() const
{
    return m_currrentRound;
}

int GetRunningGameStatusResponse::GetTimer() const
{
    return m_timer;
}

std::string GetRunningGameStatusResponse::GetCurrentWord() const
{
    return m_currentWord;
}

std::vector<int> GetRunningGameStatusResponse::GetPlayerIds() const
{
    return m_playerIds;
}

std::unordered_map<int, int> GetRunningGameStatusResponse::GetPlayerPoints() const
{
    return m_playerPoints;
}


