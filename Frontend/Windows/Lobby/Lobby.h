#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include "../../Widgets/LobbyPlayerInfoWidget/LobbyPlayerInfoWidget.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../Utils/LobbyData/LobbyData.h"
#include "../../API/Contexts/Contexts.h"
#include <QClipboard>
#include <QCloseEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QTimer>

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent = nullptr);
	~Lobby();

protected:
	void closeEvent(QCloseEvent* event) override;
	void showEvent(QShowEvent* event) override;
	void hideEvent(QHideEvent* event) override;


private:
	Ui::LobbyClass ui;
	LobbyData m_lobbyData;
	Contexts contexts;
	QTimer* m_timer;
	void addPlayerToLobbyListView(const UserInfo& userInfo);
	void updateLobbyId();
	void updateActivePlayersNumber();
	void updateLobbyAdmin();
	void updateLobbyPlayerListView();
	void hideOrShowStartGameButton();
	void updateLobbyStatus();
	void leaveLobby();
	void updateLobbyData();

private slots:
	virtual void on_pushButton_startGame_clicked();
	virtual void on_pushButton_exitLobby_clicked();
	virtual void on_pushButton_copyLobbyId_clicked();

public slots:
	void getLobbyData(const LobbyData& lobbyData);
	void getLobbyId(int lobbyId);

signals:
	void goToJoinGameWindow();
};
