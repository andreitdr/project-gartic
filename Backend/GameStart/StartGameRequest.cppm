export module StartGameRequest;
import <vector>;

export class StartGameRequest
{
public:
    StartGameRequest(const std::vector<int>& userIds);
    std::vector<int> GetUsers() const;

private:
    std::vector<int> m_userIds;
};

StartGameRequest::StartGameRequest(const std::vector<int>& userIds) : m_userIds{userIds}
{
}

std::vector<int> StartGameRequest::GetUsers() const
{
    return m_userIds;
}