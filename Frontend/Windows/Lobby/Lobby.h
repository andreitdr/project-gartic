#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include "../../Widgets/LobbyPlayerInfoWidget/LobbyPlayerInfoWidget.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
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
	LobbyData m_lobbyData;
	void addPlayerToLobbyListView(const UserInfo& userInfo);
	void updateLobbyId();
	void updateActivePlayersNumber();
	void updateLobbyAdmin();
	void updateLobbyPlayerListView();
	void hideOrShowStartGameButton();
	void updateLobbyStatus();

private slots:
	virtual void on_pushButton_startGame_clicked();
	virtual void on_pushButton_exitLobby_clicked();
	virtual void on_pushButton_copyLobbyId_clicked();

public slots:
	void getLobbyData(const LobbyData& lobbyData);

signals:
	void goToJoinGameWindow();
};
