#pragma once

#include <QMainWindow>
#include "ui_Lobby.h"

class Lobby : public QMainWindow
{
	Q_OBJECT

public:
	Lobby(QWidget *parent = nullptr);
	~Lobby();

private:
	Ui::LobbyClass ui;
};
