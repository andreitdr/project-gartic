#pragma once

#include <QMainWindow>
#include "ui_CreatePrivateRoom.h"
#include "../../Utils/UserInfo/UserInfo.h"

class CreatePrivateRoom : public QMainWindow
{
	Q_OBJECT

public:
	CreatePrivateRoom(QWidget *parent = nullptr);
	~CreatePrivateRoom();

private:
	Ui::CreatePrivateRoomClass ui;
	int m_privateRoomCode;
	UserInfo m_user;

signals:
	void goToJoinGameWindow();
	void goToLobbyWindow();

private slots:
	virtual void on_pushButton_goBack_clicked();
	virtual void on_pushButton_joinRoom_clicked();
	virtual void on_pushButton_generateCode_clicked();

};
