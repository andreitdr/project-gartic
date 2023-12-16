export module JoinLobbyResponse;

export import BaseResponse;
import <string>;

export class JoinLobbyResponse final : public BaseResponse
{
public:
	JoinLobbyResponse();
	JoinLobbyResponse(const std::string& message);
};

JoinLobbyResponse::JoinLobbyResponse()
{
	m_successState = true;
}

JoinLobbyResponse::JoinLobbyResponse(const std::string& message)
{
	m_successState = false;
	AppendMessage(message);
}


