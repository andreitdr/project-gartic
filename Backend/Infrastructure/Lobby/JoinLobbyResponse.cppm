export module JoinLobbyResponse;

export import BaseResponse;
import <string>;

export class JoinLobbyResponse final : public BaseResponse
{
public:
	JoinLobbyResponse();
	JoinLobbyResponse(const std::string& message);
	JoinLobbyResponse& operator+(const JoinLobbyResponse& other);
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

JoinLobbyResponse& JoinLobbyResponse::operator+(const JoinLobbyResponse& other)
{
	BaseResponse::operator+(other);
	return *this;
}

