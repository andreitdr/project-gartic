#pragma once

#include <QMainWindow>
#include "ui_JoinGame.h"
#include "../../API/Contexts/Contexts.h"

class JoinGame : public QMainWindow
{
	Q_OBJECT

public:
	explicit JoinGame(Contexts* contexts, QWidget *parent = nullptr);
	~JoinGame();

private:
	Ui::JoinGameClass ui;
	Contexts* contexts;
	void updateUserInfoDisplay();

protected:
	void showEvent(QShowEvent* event) override;

signals:
	void goToLoginWindow();
	void goToUserProfileWindow();
	void goToLobbyWindow();
	void goToJoinRoomWindow();
	void sendLobbyData(const LobbyData& lobbyData);

private slots:
	virtual void on_pushButton_userProfile_clicked();
	virtual void on_pushButton_createPrivateGame_clicked();
	virtual void on_pushButton_logOut_clicked();
	virtual void on_pushButton_joinGame_clicked();

};
