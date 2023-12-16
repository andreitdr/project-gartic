#pragma once
#include <QObject>
#include "../../Windows/Login/Login.h"
#include "../../Windows/Register/Register.h"
#include "../../Windows/JoinGame/JoinGame.h"
#include "../../Windows/UserProfile/UserProfile.h"
#include "../../Windows/JoinRoom/JoinRoom.h"
#include "../../Windows/Lobby/Lobby.h"
#include "../../Windows/GameWindow/GameWindow.h"

class WindowManager : public QObject {
    Q_OBJECT

public:
    WindowManager(QObject* parent = nullptr);
    ~WindowManager();

public slots:
    void showLoginWindow();
    void showRegisterWindow();
    void showJoinGameWindow();
    void showUserProfileWindow();
    void showJoinRoomWindow();
    void showLobbyWindow();
    void showGameWindow();

private:
    Login* m_loginWindow;
    Register* m_registerWindow;
    JoinGame* m_joinGameWindow;
    UserProfile* m_userProfileWindow;
    JoinRoom* m_joinRoomWindow;
    Lobby* m_lobbyWindow;
    GameWindow* m_gameWindow;
    void setupConnections();
};
