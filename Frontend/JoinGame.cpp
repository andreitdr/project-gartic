#include "JoinGame.h"

JoinGame::JoinGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	userProfileWindow = new UserProfile();
	connect(userProfileWindow, &UserProfile::joinGameWindow, this, &JoinGame::show);
	createPrivateRoomWindow = new CreatePrivateRoom();
	connect(createPrivateRoomWindow, &CreatePrivateRoom::joinGameWindow, this, &JoinGame::show);
	joinRoomWindow= new JoinRoom();
	connect(joinRoomWindow, &JoinRoom::joinGameWindow, this, &JoinGame::show);
	connect(this, SIGNAL(sendUser(const UserInfo&)), userProfileWindow, SLOT(getUser(const UserInfo&)));
	connect(this, SIGNAL(sendUser(const UserInfo&)), createPrivateRoomWindow, SLOT(getUser(const UserInfo&)));
}

JoinGame::~JoinGame()
{}

void JoinGame::getUser(const UserInfo& user)
{
	m_user = user;
	QLineEdit* usernameLineEdit = findChild<QLineEdit*>("lineEdit_usernameDisplay");
	if (usernameLineEdit) {
		
		std::string m_username = "@" + m_user.getUsername();
		QString username = QString::fromUtf8(m_username);
		usernameLineEdit->setText(username);
	}
}

void JoinGame::on_pushButton_userProfile_clicked()
{
	emit sendUser(m_user);
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

void JoinGame::on_pushButton_joinGame_clicked()
{
joinRoomWindow->show();
	this->hide();
}
