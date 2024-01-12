#pragma once

#include "../BaseResponse.h"
#include "../../DataTypes/Game/PlayerFinishedGame.h"
#include <vector>


class UserMatchHistoryResponse : public BaseResponse
{
public:
    UserMatchHistoryResponse();
    UserMatchHistoryResponse(const std::vector<PlayerFinishedGame>& finished_games);
    UserMatchHistoryResponse(const std::string& response);

    std::vector<PlayerFinishedGame> GetFinishedGames() const;
    int GetTotalPoints() const;
    int GetAveragePoints() const;

private:
    std::vector<PlayerFinishedGame> m_listOfFinishedGames;
    int m_pointsAverage;
    int m_pointsTotal;
};
