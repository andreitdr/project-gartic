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

void JoinGame::updateUserInfoDisplay()
{
	CurrentUser& user = CurrentUser::getInstance();
	QString username = QString::fromUtf8(user.getUsername().c_str());
	ui.lineEdit_usernameDisplay->setText("@" + username);
}

void JoinGame::showEvent(QShowEvent* event)
{
	QWidget::showEvent(event);
	updateUserInfoDisplay();
}

void JoinGame::on_pushButton_createPrivateGame_clicked()
{
	emit goToLobbyWindow();
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
