export module BaseResponse;
import <string>;
import <vector>;

export class BaseResponse
{
public:
    BaseResponse();
    std::vector<std::string> m_messages;
    bool m_successState;
    
    void AppendMessage(const std::string& message);
    
    explicit operator bool()const;
};

BaseResponse::BaseResponse()
{
    m_successState = false;
    m_messages = {};
}

void BaseResponse::AppendMessage(const std::string& message)
{
    m_messages.emplace_back(message);
}

BaseResponse::operator bool() const
{
    return m_successState;
}
