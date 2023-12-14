#include "JoinGame.h"

JoinGame::JoinGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

JoinGame::~JoinGame()
{}
void JoinGame::on_pushButton_userProfile_clicked()
{
	emit goToUserProfileWindow();
	this->hide();
}

void JoinGame::on_pushButton_createPrivateGame_clicked()
{
	emit goToCreatePrivateRoomWindow();
	this->hide();
}

void JoinGame::on_pushButton_logOut_clicked()
{
	emit goToLoginWindow();
	this->hide();
}

void JoinGame::on_pushButton_joinGame_clicked()
{
	goToJoinRoomWindow();
	this->hide();
}
