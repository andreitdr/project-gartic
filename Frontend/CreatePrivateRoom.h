#pragma once

#include <QMainWindow>
#include "ui_CreatePrivateRoom.h"
#include <QClipboard>

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

private slots:
	virtual void on_pushButton_goBack_clicked();
	virtual void on_pushButton_copyCode_clicked();
	virtual void on_pushButton_generateCode_clicked();
};
