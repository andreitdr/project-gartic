#include "WindowManager.h"

WindowManager::WindowManager(QObject* parent) : QObject{ parent },
	m_loginWindow{ std::make_unique<Login>() },
	m_registerWindow{ std::make_unique<Register>() },
	m_joinGameWindow{ std::make_unique <JoinGame>() },
	m_userProfileWindow{ std::make_unique <UserProfile>() },
	m_joinRoomWindow{ std::make_unique <JoinRoom>() },
	m_lobbyWindow{ std::make_unique <Lobby>() },
	m_gameWindow{ std::make_unique <GameWindow>() }
{
	setupConnections();
}

void WindowManager::setupConnections()
{
	//Login connections
	connect(m_loginWindow.get(), &Login::goToRegister, this, &WindowManager::showRegisterWindow);
	connect(m_loginWindow.get(), &Login::goToJoinGame, this, &WindowManager::showJoinGameWindow);

	//Register connections
	connect(m_registerWindow.get(), &Register::goToLogin, this, &WindowManager::showLoginWindow);

	//JoinGame connections
	connect(m_joinGameWindow.get(), &JoinGame::goToLoginWindow, this, &WindowManager::showLoginWindow);
	connect(m_joinGameWindow.get(), &JoinGame::goToUserProfileWindow, this, &WindowManager::showUserProfileWindow);
	connect(m_joinGameWindow.get(), &JoinGame::goToLobbyWindow, this, &WindowManager::showLobbyWindow);
	connect(m_joinGameWindow.get(), &JoinGame::goToJoinRoomWindow, this, &WindowManager::showJoinRoomWindow);
	connect(m_joinGameWindow.get(), &JoinGame::sendLobbyData, m_lobbyWindow.get(), &Lobby::getLobbyData);

	//UserProfile connections
	connect(m_userProfileWindow.get(), &UserProfile::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);

	//JoinRoom connections
	connect(m_joinRoomWindow.get(), &JoinRoom::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
	connect(m_joinRoomWindow.get(), &JoinRoom::goToLobbyWindow, this, &WindowManager::showLobbyWindow);

	//Lobby connections
	connect(m_lobbyWindow.get(), &Lobby::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
}

void WindowManager::showLoginWindow()
{
	m_loginWindow->show();
}

void WindowManager::showRegisterWindow()
{
	m_registerWindow->show();
}

void WindowManager::showJoinGameWindow()
{
	m_joinGameWindow->show();
}

void WindowManager::showUserProfileWindow()
{
	m_userProfileWindow->show();
}

void WindowManager::showJoinRoomWindow()
{
	m_joinRoomWindow->show();
}

void WindowManager::showLobbyWindow()
{
	m_lobbyWindow->show();
}

void WindowManager::showGameWindow()
{
	m_gameWindow->show();
}
