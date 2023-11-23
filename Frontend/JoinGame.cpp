#include "JoinGame.h"

JoinGame::JoinGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	userProfileWindow = new UserProfile();
	connect(userProfileWindow, &UserProfile::joinGameWindow, this, &JoinGame::show);
	createPrivateRoomWindow = new CreatePrivateRoom();
	connect(createPrivateRoomWindow, &CreatePrivateRoom::joinGameWindow, this, &JoinGame::show);
	connect(this, SIGNAL(sendUsername(const QString&)), userProfileWindow, SLOT(getUsername(const QString&)));

	
}

JoinGame::~JoinGame()
{}

void JoinGame::getUsername(const QString& username)
{
	m_username = username;
	QLineEdit* usernameLineEdit = findChild<QLineEdit*>("lineEdit_usernameDisplay");
	if (usernameLineEdit) {
		QString temp = "@" + username;

		usernameLineEdit->setText(temp);
	}
}

void JoinGame::on_pushButton_userProfile_clicked()
{
	emit sendUsername(m_username);
	userProfileWindow->show();
	this->hide();
}

void JoinGame::on_pushButton_createPrivateGame_clicked()
{
	createPrivateRoomWindow->show();
	this->hide();
}

void JoinGame::on_pushButton_logOut_clicked()
{
	emit loginWindow();
	this->hide();
}
