#pragma once

#include <QMainWindow>
#include "ui_CreatePrivateRoom.h"

class CreatePrivateRoom : public QMainWindow
{
	Q_OBJECT

public:
	CreatePrivateRoom(QWidget *parent = nullptr);
	~CreatePrivateRoom();

private:
	Ui::CreatePrivateRoomClass ui;

signals:
	void joinGameWindow();
};
