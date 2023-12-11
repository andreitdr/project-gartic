#include "LobbyData.h"

LobbyData::LobbyData()
{
	m_lobbyID = 0;
}

LobbyData::~LobbyData()
{
}

void LobbyData::SetLobbyID(int lobbyID)
{
	m_lobbyID=lobbyID;
}

int LobbyData::GetLobbyID() const
{
	return m_lobbyID;
}

void LobbyData::SetLobbyAdmin(UserInfo user)
{
	m_lobbyAdmin=user;
}

UserInfo LobbyData::GetLobbyAdmin() const
{
	return m_lobbyAdmin;
}

void LobbyData::AddUser(UserInfo user)
{
	m_lobbyUsers.push_back(user);
}

void LobbyData::RemoveUser(UserInfo user)
{
	for (int i=0; i<m_lobbyUsers.size(); i++)
	{
		if (m_lobbyUsers[i].getUserId()==user.getUserId())
		{
			m_lobbyUsers.erase(m_lobbyUsers.begin()+i);
			break;
		}
	}
}

std::vector<UserInfo> LobbyData::GetUsers() const
{
	return m_lobbyUsers;
}
