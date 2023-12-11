#pragma once
#include "../../Utils/UserInfo/UserInfo.h"
#include <vector>

class LobbyData
{
public:
	LobbyData();
	~LobbyData();

	void SetLobbyID(int lobbyID);
	int GetLobbyID() const;

	void SetLobbyAdmin(UserInfo user);
	UserInfo GetLobbyAdmin() const;

	void AddUser(UserInfo user);
	void RemoveUser(UserInfo user);
	std::vector<UserInfo> GetUsers() const;
private:
	int m_lobbyID;
	UserInfo m_lobbyAdmin;
	std::vector<UserInfo> m_lobbyUsers;
};

