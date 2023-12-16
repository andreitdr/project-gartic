#include "WindowManager.h"

WindowManager::WindowManager(QObject* parent) : QObject{ parent },
	m_loginWindow{ new Login() },
	m_registerWindow{ new Register() },
	m_joinGameWindow{ new JoinGame() },
	m_userProfileWindow{ new UserProfile() },
	m_joinRoomWindow{ new JoinRoom() },
	m_lobbyWindow{ new Lobby() },
	m_gameWindow{ new GameWindow() } 
{
	setupConnections();
}

WindowManager::~WindowManager() 
{
	delete m_loginWindow;
	delete m_registerWindow;
	delete m_joinGameWindow;
	delete m_userProfileWindow;
	delete m_joinRoomWindow;
	delete m_lobbyWindow;
	delete m_gameWindow;
}

void WindowManager::setupConnections()
{
	//Login connections
	connect(m_loginWindow, &Login::goToRegister, this, &WindowManager::showRegisterWindow);
	connect(m_loginWindow,&Login::goToJoinGame, this, &WindowManager::showJoinGameWindow);

	//Register connections
	connect(m_registerWindow, &Register::goToLogin, this, &WindowManager::showLoginWindow);

	//JoinGame connections
	connect(m_joinGameWindow, &JoinGame::goToLoginWindow, this, &WindowManager::showLoginWindow);
	connect(m_joinGameWindow, &JoinGame::goToUserProfileWindow, this, &WindowManager::showUserProfileWindow);
	connect(m_joinGameWindow, &JoinGame::goToLobbyWindow, this, &WindowManager::showLobbyWindow);
	connect(m_joinGameWindow, &JoinGame::goToJoinRoomWindow, this, &WindowManager::showJoinRoomWindow);

	//UserProfile connections
	connect(m_userProfileWindow, &UserProfile::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);

	//JoinRoom connections
	connect(m_joinRoomWindow, &JoinRoom::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
	connect(m_joinRoomWindow, &JoinRoom::goToLobbyWindow, this, &WindowManager::showLobbyWindow);

	//Lobby connections
	connect(m_lobbyWindow, &Lobby::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
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
