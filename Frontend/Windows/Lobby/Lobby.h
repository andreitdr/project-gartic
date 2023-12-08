#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"
#include "../../Widgets/LobbyPlayerInfoWidget/LobbyPlayerInfoWidget.h"

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent = nullptr);
	~Lobby();

private:
	Ui::LobbyClass ui;
	void updateActivePlayersNumber(int playerNumber);
	void addPlayerToLobbyListView(const QString& username, const QString& surname, const QString& givenName, bool isAdmin);
	void removePlayerFromLobbyListView(const QString& username);

private slots:
	virtual void on_pushButton_startGame_clicked();
	virtual void on_pushButton_exitLobby_clicked();
};
