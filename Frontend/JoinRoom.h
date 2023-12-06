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
	void joinGameWindow();
};
