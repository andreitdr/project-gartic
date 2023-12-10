export module JoinLobbyRequest;
import <string>;


export class JoinLobbyRequest
{
public:
	JoinLobbyRequest(const int lobbyId, const int userId);

	int GetLobbyId() const;
	int GetUserId() const;

private:
	int m_lobbyId;
	int m_userId;
};

JoinLobbyRequest::JoinLobbyRequest(const int lobbyId, const int userId) :
m_lobbyId{ lobbyId } , m_userId{ userId }
{
}

int JoinLobbyRequest::GetLobbyId() const
{
	return m_lobbyId;
}

int JoinLobbyRequest::GetUserId() const
{
	return m_userId;
}
