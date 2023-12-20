#pragma once

#include <QMainWindow>
#include "ui_JoinRoom.h"

class JoinRoom : public QMainWindow
{
	Q_OBJECT

public:
	JoinRoom(QWidget *parent = nullptr);
	~JoinRoom();

private:
	Ui::JoinRoomClass ui;

signals:
	void goToJoinGameWindow();
	void goToLobbyWindow();

private slots:
	virtual void on_pushButton_goBack_clicked();
	virtual void on_pushButton_JoinPrivateRoom_clicked();
	virtual void on_pushButton_JoinRandomGame_clicked();
};
