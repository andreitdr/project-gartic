#pragma once

#include <QMainWindow>
#include "ui_CreatePrivateRoom.h"
#include "UserInfo.h"
#include <cstdlib>
#include <ctime>


class CreatePrivateRoom : public QMainWindow
{
	Q_OBJECT

public:
	CreatePrivateRoom(QWidget *parent = nullptr);
	~CreatePrivateRoom();

private:
	Ui::CreatePrivateRoomClass ui;
	int generateRandomNumber();
	int m_privateRoomCode;
	UserInfo m_user;

signals:
	void joinGameWindow();

private slots:
	virtual void on_pushButton_goBack_clicked();
	virtual void on_pushButton_pushButton_joinRoom_clicked();
	virtual void on_pushButton_generateCode_clicked();

public slots:
	virtual void getUser(const UserInfo&);
};
