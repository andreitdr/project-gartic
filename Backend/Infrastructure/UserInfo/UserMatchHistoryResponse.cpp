#include "UserMatchHistoryResponse.h"

UserMatchHistoryResponse::UserMatchHistoryResponse() : BaseResponse(), m_pointsAverage(0), m_pointsTotal(0)
{
        m_listOfFinishedGames = std::vector<PlayerFinishedGame>();
        m_successState = true;
}

UserMatchHistoryResponse::UserMatchHistoryResponse(const std::vector<PlayerFinishedGame>& finished_games) : BaseResponse(), m_listOfFinishedGames{finished_games}
{
        m_pointsTotal = 0;
        for(auto game:finished_games)
                m_pointsTotal += game.m_pointsEarned;

        m_pointsAverage = m_pointsTotal/finished_games.size();
        m_successState = true;
}

UserMatchHistoryResponse::UserMatchHistoryResponse(const std::string& response) : BaseResponse()
{
        m_successState = false;
        AppendMessage(response);
}

std::vector<PlayerFinishedGame> UserMatchHistoryResponse::GetFinishedGames() const
{
    return  m_listOfFinishedGames;
}

int UserMatchHistoryResponse::GetTotalPoints() const
{return m_pointsTotal;
}

int UserMatchHistoryResponse::GetAveragePoints() const
{return m_pointsAverage;
}




