#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include "../../Widgets/LobbyPlayerInfoWidget/LobbyPlayerInfoWidget.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Utils/UserInfo/UserInfo.h"
#include "../../Utils/LobbyData/LobbyData.h"
#include <QClipboard>
#include <QCloseEvent>

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent = nullptr);
	~Lobby();

protected:
	void closeEvent(QCloseEvent* event) override;

private:
	Ui::LobbyClass ui;
	UserInfo m_user;
	LobbyData m_lobbyData;
	void updateActivePlayersNumber(int playerNumber);
	void addPlayerToLobbyListView(const QString& username, const QString& surname, const QString& givenName, bool isAdmin);
	void removePlayerFromLobbyListView(const QString& username);
	void hideOrShowStartGameButton();
	void updateLobbyId(int lobbyId);

private slots:
	virtual void on_pushButton_startGame_clicked();
	virtual void on_pushButton_exitLobby_clicked();
	virtual void on_pushButton_copyLobbyId_clicked();

signals:
	void goToJoinGameWindow();
};
