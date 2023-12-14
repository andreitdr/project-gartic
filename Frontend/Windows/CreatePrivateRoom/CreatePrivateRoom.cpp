#include "CreatePrivateRoom.h"

CreatePrivateRoom::CreatePrivateRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CreatePrivateRoom::~CreatePrivateRoom()
{}

void CreatePrivateRoom::on_pushButton_joinRoom_clicked()
{
	emit goToLobbyWindow();
	this->hide();
}

void CreatePrivateRoom::on_pushButton_generateCode_clicked()
{
}

void CreatePrivateRoom::on_pushButton_goBack_clicked()
{
	emit goToJoinGameWindow();
	this->hide();
}