#pragma once
#include <string>
#include <vector>

class BaseResponse
{
public:
    BaseResponse();
    std::vector<std::string> m_messages;
    bool m_successState;

    void AppendMessage(const std::string& message);

    explicit operator bool() const;
};
