#pragma once
#include <QObject>
#include <memory>
#include "../../Windows/Login/Login.h"
#include "../../Windows/Register/Register.h"
#include "../../Windows/JoinGame/JoinGame.h"
#include "../../Windows/UserProfile/UserProfile.h"
#include "../../Windows/JoinRoom/JoinRoom.h"
#include "../../Windows/Lobby/Lobby.h"
#include "../../Windows/GameWindow/GameWindow.h"
#include "../../API/Contexts/Contexts.h"

class WindowManager : public QObject {
    Q_OBJECT

public:
    WindowManager(QObject* parent = nullptr);
    ~WindowManager() = default;

public slots:
    void showLoginWindow();
    void showRegisterWindow();
    void showJoinGameWindow();
    void showUserProfileWindow();
    void showJoinRoomWindow();
    void showLobbyWindow();
    void showGameWindow();
    void onWindowHidden(const QPoint& position);

private:
    Contexts m_contexts;
    std::unique_ptr<Login> m_loginWindow;
    std::unique_ptr<Register> m_registerWindow;
    std::unique_ptr<JoinGame> m_joinGameWindow;
    std::unique_ptr<UserProfile> m_userProfileWindow;
    std::unique_ptr<JoinRoom> m_joinRoomWindow;
    std::unique_ptr<Lobby> m_lobbyWindow;
    std::unique_ptr<GameWindow> m_gameWindow;
    void setupConnections();

    QPoint lastWindowPosition;
    void setWindowPosition(QWidget* window);
};
