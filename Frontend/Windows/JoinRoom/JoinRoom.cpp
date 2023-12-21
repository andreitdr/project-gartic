#include "JoinRoom.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"

JoinRoom::JoinRoom(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
}

JoinRoom::~JoinRoom()
{}

void JoinRoom::on_pushButton_JoinPrivateRoom_clicked()
{
	int lobbyId = ui.lineEdit_enterCode->text().toInt();
	int userId = CurrentUser::getInstance().getUserId();
	contexts->joinLobby(userId, lobbyId, [this,lobbyId](bool success, const std::string& message)
		{
			QString qmessage = QString::fromUtf8(message.c_str());
			if (success)
			{
				emit sendLobbyId(lobbyId);
				emit windowPositionChanged(this->pos());
				emit goToLobbyWindow();
				this->hide();
			}
			else
				if(message!="")
					showErrorCustomMessageBox(
						this,
						"Gartic - Join Room",
						qmessage,
						"Ok",
						[]() {}
					);
				else
			{
				showErrorCustomMessageBox(
					this,
					"Gartic - Join Room",
					"Something went wrong. Please try again later!",
					"Ok",
					[]() {}
				);
			}
		});
}

void JoinRoom::on_pushButton_JoinRandomGame_clicked()
{
	emit windowPositionChanged(this->pos());
	emit goToLobbyWindow();
	this->hide();
}

void JoinRoom::on_pushButton_goBack_clicked()
{
	emit windowPositionChanged(this->pos());
	emit goToJoinGameWindow();
	this->hide();
}