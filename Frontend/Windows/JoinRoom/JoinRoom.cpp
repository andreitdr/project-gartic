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
}

void JoinRoom::on_pushButton_JoinRandomGame_clicked()
{
}

void JoinRoom::on_pushButton_goBack_clicked()
{
	emit joinGameWindow();
	this->hide();
}

void JoinRoom::getUser(const UserInfo& user)
{
	m_user = user;
}