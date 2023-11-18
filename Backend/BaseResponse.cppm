export module BaseResponse;
import <string>;
import <vector>;

export struct BaseResponse
{
    std::vector<std::string> m_messages;
    bool m_successState;

    void AppendMessage(const std::string& message)
    {
        m_messages.emplace_back(message);
    }

    
};
