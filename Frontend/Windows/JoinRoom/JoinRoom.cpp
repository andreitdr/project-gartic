#include "JoinRoom.h"

JoinRoom::JoinRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

JoinRoom::~JoinRoom()
{}

void JoinRoom::on_pushButton_JoinPrivateRoom_clicked()
{
	emit goToLobbyWindow();
	this->hide();
}

void JoinRoom::on_pushButton_JoinRandomGame_clicked()
{
	emit goToLobbyWindow();
	this->hide();
}

void JoinRoom::on_pushButton_goBack_clicked()
{
	emit goToJoinGameWindow();
	this->hide();
}