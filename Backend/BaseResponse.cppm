export module BaseResponse;
import <string>;
import <vector>;

export class BaseResponse
{
public:
    std::vector<std::string> m_messages;
    bool m_successState;

    virtual ~BaseResponse() = default;
    void AppendMessage(const std::string& message);
    virtual BaseResponse& operator+(const BaseResponse& other);
    
    explicit operator bool()const;
};

void BaseResponse::AppendMessage(const std::string& message)
{
    m_messages.emplace_back(message);
}

BaseResponse& BaseResponse::operator+(const BaseResponse& other)
{
    m_successState = m_successState && other.m_successState;
    m_messages.insert(m_messages.end(), other.m_messages.begin(), other.m_messages.end());
    return *this;
}

BaseResponse::operator bool() const
{
    return m_successState;
}
