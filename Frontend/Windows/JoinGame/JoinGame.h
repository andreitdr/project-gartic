#pragma once

#include <QMainWindow>
#include "ui_JoinGame.h"
#include "../../Windows/UserProfile/UserProfile.h"
#include "../../Windows/CreatePrivateRoom/CreatePrivateRoom.h"
#include "../../Windows/JoinRoom/JoinRoom.h"
#include "../../Utils/UserInfo/UserInfo.h"

class JoinGame : public QMainWindow
{
	Q_OBJECT

public:
	JoinGame(QWidget *parent = nullptr);
	~JoinGame();

private:
	Ui::JoinGameClass ui;
	UserInfo m_user;
signals:
	void goToLoginWindow();
	void goToUserProfileWindow();
	void goToCreatePrivateRoomWindow();
	void goToJoinRoomWindow();
private slots:
	virtual void on_pushButton_userProfile_clicked();
	virtual void on_pushButton_createPrivateGame_clicked();
	virtual void on_pushButton_logOut_clicked();
	virtual void on_pushButton_joinGame_clicked();

};
