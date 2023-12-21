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

	void SetLobbyAdmin(const UserInfo& user);
	UserInfo GetLobbyAdmin() const;

	void AddUser(const UserInfo& user);
	void RemoveUser(const UserInfo& user);
	std::vector<UserInfo> GetUsers() const;

	LobbyData(const LobbyData& other);
	LobbyData& operator=(const LobbyData& other);

	LobbyData(LobbyData&& other) noexcept;
	LobbyData& operator=(LobbyData&& other) noexcept;

	bool operator==(const LobbyData& other) const;
private:
	int m_lobbyID;
	UserInfo m_lobbyAdmin;
	std::vector<UserInfo> m_lobbyUsers;
};

