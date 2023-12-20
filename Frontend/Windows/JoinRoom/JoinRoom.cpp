#include "JoinRoom.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"

JoinRoom::JoinRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	contexts = Contexts();
}

JoinRoom::~JoinRoom()
{}

void JoinRoom::on_pushButton_JoinPrivateRoom_clicked()
{
	int lobbyId = ui.lineEdit_enterCode->text().toInt();
	int userId = CurrentUser::getInstance().getUserId();
	contexts.joinLobby(userId, lobbyId, [this](bool success, const std::string& message)
		{
			QString qmessage = QString::fromUtf8(message.c_str());
			if (success)
			{
				emit goToLobbyWindow();
				this->hide();
			}
			else
				if(message!="")
					showErrorCustomMessageBox(
						"Gartic - Join Room",
						qmessage,
						"Ok",
						[]() {}
					);
				else
			{
				showErrorCustomMessageBox(
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
	emit goToLobbyWindow();
	this->hide();
}

void JoinRoom::on_pushButton_goBack_clicked()
{
	emit goToJoinGameWindow();
	this->hide();
}