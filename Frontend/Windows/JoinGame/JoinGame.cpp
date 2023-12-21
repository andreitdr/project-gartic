#include "JoinGame.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"


JoinGame::JoinGame(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
}

JoinGame::~JoinGame()
{}

void JoinGame::on_pushButton_userProfile_clicked()
{
	emit windowPositionChanged(this->pos());
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
	contexts->createLobby(CurrentUser::getInstance().getUserId(), [this](bool success, const std::string& message, const LobbyData& lobbyData)
		{
			if (success)
			{
				emit sendLobbyData(lobbyData);
				emit windowPositionChanged(this->pos());
				emit goToLobbyWindow();
				this->hide();
			}
			else
			{
				showErrorCustomMessageBox(
					this,
					"Gartic - Join Game",
					"Something went wrong. Please try again later!",
					"Ok",
					[]() {}
				);
			}

		});
}

void JoinGame::on_pushButton_logOut_clicked()
{
	emit windowPositionChanged(this->pos());
	emit goToLoginWindow();
	this->hide();
}

void JoinGame::on_pushButton_joinGame_clicked()
{
	emit windowPositionChanged(this->pos());
	goToJoinRoomWindow();
	this->hide();
}
