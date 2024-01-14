#include "WindowManager.h"

WindowManager::WindowManager(QObject* parent) : QObject{ parent },
	m_contexts(),
	m_loginWindow{ std::make_unique<Login>(&m_contexts)},
	m_registerWindow{ std::make_unique<Register>(&m_contexts) },
	m_joinGameWindow{ std::make_unique <JoinGame>(&m_contexts) },
	m_userProfileWindow{ std::make_unique <UserProfile>(&m_contexts) },
	m_joinRoomWindow{ std::make_unique <JoinRoom>(&m_contexts) },
	m_lobbyWindow{ std::make_unique <Lobby>(&m_contexts) },
	m_gameWindow{ std::make_unique <GameWindow>(&m_contexts) }
{
	setupConnections();
}

void WindowManager::setupConnections()
{
	//Login connections
	connect(m_loginWindow.get(), &Login::goToRegister, this, &WindowManager::showRegisterWindow);
	connect(m_loginWindow.get(), &Login::goToJoinGame, this, &WindowManager::showJoinGameWindow);
	connect(m_loginWindow.get(), &Login::windowPositionChanged, this, &WindowManager::onWindowHidden);

	//Register connections
	connect(m_registerWindow.get(), &Register::goToLogin, this, &WindowManager::showLoginWindow);
	connect(m_registerWindow.get(), &Register::windowPositionChanged, this, &WindowManager::onWindowHidden);

	//JoinGame connections
	connect(m_joinGameWindow.get(), &JoinGame::goToLoginWindow, this, &WindowManager::showLoginWindow);
	connect(m_joinGameWindow.get(), &JoinGame::goToUserProfileWindow, this, &WindowManager::showUserProfileWindow);
	connect(m_joinGameWindow.get(), &JoinGame::goToLobbyWindow, this, &WindowManager::showLobbyWindow);
	connect(m_joinGameWindow.get(), &JoinGame::goToJoinRoomWindow, this, &WindowManager::showJoinRoomWindow);
	connect(m_joinGameWindow.get(), &JoinGame::sendLobbyData, m_lobbyWindow.get(), &Lobby::getLobbyData);
	connect(m_joinGameWindow.get(), &JoinGame::windowPositionChanged, this, &WindowManager::onWindowHidden);

	//UserProfile connections
	connect(m_userProfileWindow.get(), &UserProfile::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
	connect(m_userProfileWindow.get(), &UserProfile::windowPositionChanged, this, &WindowManager::onWindowHidden);

	//JoinRoom connections
	connect(m_joinRoomWindow.get(), &JoinRoom::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
	connect(m_joinRoomWindow.get(), &JoinRoom::goToLobbyWindow, this, &WindowManager::showLobbyWindow);
	connect(m_joinRoomWindow.get(), &JoinRoom::sendLobbyId, m_lobbyWindow.get(), &Lobby::getLobbyId);
	connect(m_joinRoomWindow.get(), &JoinRoom::windowPositionChanged, this, &WindowManager::onWindowHidden);

	//Lobby connections
	connect(m_lobbyWindow.get(), &Lobby::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
	connect(m_lobbyWindow.get(), &Lobby::goToGameWindow, this, &WindowManager::showGameWindow);
	connect(m_lobbyWindow.get(), &Lobby::windowPositionChanged, this, &WindowManager::onWindowHidden);
	connect(m_lobbyWindow.get(), &Lobby::sendGameId, m_gameWindow.get(), &GameWindow::getGameId);

	//Game connections
	connect(m_gameWindow.get(), &GameWindow::goToJoinGameWindow, this, &WindowManager::showJoinGameWindow);
	connect(m_gameWindow.get(), &GameWindow::windowPositionChanged, this, &WindowManager::onWindowHidden);
}

void WindowManager::setWindowPosition(QWidget* window)
{
	if (!lastWindowPosition.isNull()) {
		window->move(lastWindowPosition);
	}
}

void WindowManager::showLoginWindow()
{
	setWindowPosition(m_loginWindow.get());
	m_loginWindow->show();
}

void WindowManager::showRegisterWindow()
{
	setWindowPosition(m_registerWindow.get());
	m_registerWindow->show();
}

void WindowManager::showJoinGameWindow()
{
	setWindowPosition(m_joinGameWindow.get());
	m_joinGameWindow->show();
}

void WindowManager::showUserProfileWindow()
{
	setWindowPosition(m_userProfileWindow.get());
	m_userProfileWindow->show();
}

void WindowManager::showJoinRoomWindow()
{
	setWindowPosition(m_joinRoomWindow.get());
	m_joinRoomWindow->show();
}

void WindowManager::showLobbyWindow()
{
	setWindowPosition(m_lobbyWindow.get());
	m_lobbyWindow->show();
}

void WindowManager::showGameWindow()
{
	setWindowPosition(m_gameWindow.get());
	m_gameWindow->show();
}

void WindowManager::onWindowHidden(const QPoint& position)
{
	lastWindowPosition = position;
}
