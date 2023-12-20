#include "JoinRoom.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../API/Contexts/Contexts.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"

JoinRoom::JoinRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

JoinRoom::~JoinRoom()
{}

void JoinRoom::on_pushButton_JoinPrivateRoom_clicked()
{
	Contexts contexts;
	int lobbyId = ui.lineEdit_enterCode->text().toInt();
	int userId = CurrentUser::getInstance().getUserId();
	contexts.joinLobby(userId, lobbyId, [this](bool success, const std::string& message)
		{
			if (success)
			{
				emit goToLobbyWindow();
				this->hide();
			}
			else
			{
				showErrorCustomMessageBox(
					"Gartic - Login",
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