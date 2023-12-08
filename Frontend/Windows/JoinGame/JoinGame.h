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
	UserProfile* userProfileWindow = nullptr;
	CreatePrivateRoom* createPrivateRoomWindow = nullptr;
	JoinRoom* joinRoomWindow = nullptr;
	UserInfo m_user;
signals:
	void loginWindow();
	void sendUser(const UserInfo&);
private slots:
	virtual void on_pushButton_userProfile_clicked();
	virtual void on_pushButton_createPrivateGame_clicked();
	virtual void on_pushButton_logOut_clicked();
	virtual void on_pushButton_joinGame_clicked();
public slots:
	virtual void getUser(const UserInfo&);

};
