export module StartGameRequest;
import <vector>;

export class StartGameRequest
{
public:
    StartGameRequest(const std::vector<uint32_t>& userIds);
    std::vector<uint32_t> GetUsers() const;

private:
    std::vector<uint32_t> m_userIds;
};

StartGameRequest::StartGameRequest(const std::vector<uint32_t>& userIds) : m_userIds{userIds}
{
}

std::vector<uint32_t> StartGameRequest::GetUsers() const
{
    return m_userIds;
}