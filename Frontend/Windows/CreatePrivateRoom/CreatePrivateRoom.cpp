#include "CreatePrivateRoom.h"

CreatePrivateRoom::CreatePrivateRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CreatePrivateRoom::~CreatePrivateRoom()
{}

int CreatePrivateRoom::generateRandomNumber()
{
	srand(time(0));
	return rand() % 900000 + 100000;
}

void CreatePrivateRoom::on_pushButton_pushButton_joinRoom_clicked()
{
	//to be implemented
}

void CreatePrivateRoom::on_pushButton_generateCode_clicked()
{
	m_privateRoomCode = generateRandomNumber();
	QString stringCode= QString::number(m_privateRoomCode);
	ui.lineEdit_viewCode->setText(stringCode);
}

void CreatePrivateRoom::on_pushButton_goBack_clicked()
{
	emit joinGameWindow();
	this->hide();
}

void CreatePrivateRoom::getUser(const UserInfo& user)
{
	m_user = user;
}