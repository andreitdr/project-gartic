export module LeaveLobbyRequest;


export class LeaveLobbyRequest
{
public:
    LeaveLobbyRequest(const int lobby_id,const int user_id);

    int GetLobbyId() const;
    int GetUserId() const;

private:
    int m_lobbyId;
    int m_userId;
};

LeaveLobbyRequest::LeaveLobbyRequest(const int lobby_id, const int user_id):
m_lobbyId{lobby_id},
m_userId{user_id}
{
}

int LeaveLobbyRequest::GetLobbyId() const
{
    return m_lobbyId;
}

int LeaveLobbyRequest::GetUserId() const
{
    return m_userId;
}
