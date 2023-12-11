export module LeaveLobbyResponse;

import <string>;

export import BaseResponse;


export class LeaveLobbyResponse : public BaseResponse
{
public:
    LeaveLobbyResponse();
    LeaveLobbyResponse(const std::string& message);
};

LeaveLobbyResponse::LeaveLobbyResponse()
{
    m_successState=true;
}

LeaveLobbyResponse::LeaveLobbyResponse(const std::string& message)
{
    m_successState=false;
    AppendMessage(message);
}
