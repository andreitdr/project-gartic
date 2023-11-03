#pragma once

#include <QMainWindow>
#include "ui_JoinGame.h"

class JoinGame : public QMainWindow
{
	Q_OBJECT

public:
	JoinGame(QWidget *parent = nullptr);
	~JoinGame();

private:
	Ui::JoinGameClass ui;
signals:
	void loginWindow();
};
