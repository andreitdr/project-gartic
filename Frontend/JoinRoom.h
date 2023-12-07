#pragma once

#include <QMainWindow>
#include "ui_JoinRoom.h"
#include "UserInfo.h"

class JoinRoom : public QMainWindow
{
	Q_OBJECT

public:
	JoinRoom(QWidget *parent = nullptr);
	~JoinRoom();

private:
	Ui::JoinRoomClass ui;
	UserInfo m_user;

signals:
	void joinGameWindow();

private slots:
	virtual void on_pushButton_goBack_clicked();
	virtual void on_pushButton_JoinPrivateRoom_clicked();
	virtual void on_pushButton_JoinRandomGame_clicked();

public slots:
	virtual void getUser(const UserInfo&);
};
