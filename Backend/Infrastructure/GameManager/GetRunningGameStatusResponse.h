#pragma once
#include "../BaseResponse.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class GetRunningGameStatusResponse : public BaseResponse
{
public:
    GetRunningGameStatusResponse(const std::string& message);
    GetRunningGameStatusResponse(const std::string& message, bool success);
    GetRunningGameStatusResponse(bool success);
    GetRunningGameStatusResponse(int playerDrawingId, int currentRound, int timer, const std::string& currentWord, const std::vector<int>& playerIds, const std::unordered_map<int, int>& playerPoints);

    int GetPlayerDrawingId() const;
    int GetCurrentRound() const;
    int GetTimer() const;

    std::string GetCurrentWord() const;

    std::vector<int> GetPlayerIds() const;
    std::unordered_map<int, int> GetPlayerPoints() const;
private:
    int m_playerDrawingId;
    int m_currrentRound;
    int m_timer;

    std::string m_currentWord;
    
    std::vector<int> m_playerIds;
    std::unordered_map<int, int> m_playerPoints;
};
