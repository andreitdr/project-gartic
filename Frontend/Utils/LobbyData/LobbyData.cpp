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

LobbyData::LobbyData(const LobbyData& other) :
	m_lobbyID{ other.m_lobbyID }, 
	m_lobbyAdmin{ other.m_lobbyAdmin }, 
	m_lobbyUsers{ other.m_lobbyUsers }
{

}

LobbyData& LobbyData::operator=(const LobbyData& other)
{
	if (this != &other)
	{
		m_lobbyID = other.m_lobbyID;
		m_lobbyAdmin = other.m_lobbyAdmin;
		m_lobbyUsers = other.m_lobbyUsers;
	}
	return *this;
}

LobbyData::LobbyData(LobbyData&& other) noexcept : 
	m_lobbyID{ other.m_lobbyID },
	m_lobbyAdmin{ std::move(other.m_lobbyAdmin) },
	m_lobbyUsers{ std::move(other.m_lobbyUsers) }
{
}

LobbyData& LobbyData::operator=(LobbyData&& other) noexcept
{
	if (this != &other)
	{
		m_lobbyID = other.m_lobbyID;
		m_lobbyAdmin = std::move(other.m_lobbyAdmin);
		m_lobbyUsers = std::move(other.m_lobbyUsers);
	}
	return *this;
}

bool LobbyData::operator==(const LobbyData& other) const
{
	if(m_lobbyID!=other.m_lobbyID)
		return false;

	if(m_lobbyAdmin.getUserId()!=other.m_lobbyAdmin.getUserId())
		return false;

	if(m_lobbyUsers.size()!=other.m_lobbyUsers.size())
		return false;

	for (int i = 0; i < m_lobbyUsers.size(); i++)
		if (m_lobbyUsers[i].getUserId()!=other.m_lobbyUsers[i].getUserId())
			return false;

	return true;
}
