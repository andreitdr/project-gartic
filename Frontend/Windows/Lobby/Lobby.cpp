#include "Lobby.h"

Lobby::Lobby(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Lobby::~Lobby()
{}

void Lobby::closeEvent(QCloseEvent * event)
{
    bool shouldClose = false;

   showConfirmActionCustomMessageBox(
        "Lobby - Leave lobby",
        "Are you sure you want to leave the lobby?",
        "Yes",
        "No",
        [&shouldClose]() {
            shouldClose = true;
        }
    );

    if (shouldClose)
    {
        emit goToJoinGameWindow();
        this->hide();
    }
    else 
    {
        event->ignore();
    }
}

void Lobby::updateActivePlayersNumber()
{
	int playerNumber = m_lobbyData.GetUsers().size();
	ui.label_playersActiveNumber->setText(QString::number(playerNumber));
}

void Lobby::addPlayerToLobbyListView(const UserInfo& userInfo)
{
    QListWidgetItem* item = new QListWidgetItem(ui.listWidget_players);
    QString username = QString::fromUtf8(userInfo.getUsername().c_str());
    QString surname = QString::fromUtf8(userInfo.getSurname().c_str());
    QString givenName = QString::fromUtf8(userInfo.getGivenName().c_str());
    LobbyPlayerInfoWidget* playerWidget = new LobbyPlayerInfoWidget(username, surname, givenName);

    const QSize fixedSize = QSize(281, 80);
	item->setSizeHint(fixedSize);

	ui.listWidget_players->setItemWidget(item, playerWidget);
}

void Lobby::hideOrShowStartGameButton()
{
    if((m_lobbyData.GetLobbyAdmin().getUsername()!=CurrentUser::getInstance().getUsername()) || (ui.listWidget_players->count() == 1))
    {
        ui.pushButton_startGame->setEnabled(false);
        ui.pushButton_startGame->setStyleSheet("QPushButton { background-color: rgb(255, 201, 108); color:grey; }");
    }
    else
    {
        ui.pushButton_startGame->setEnabled(true);
        ui.pushButton_startGame->setStyleSheet("QPushButton { background-color: rgb(255, 191, 0); color:rgb(0,0,0); }  QPushButton:hover, QPushButton:pressed {background-color: rgb(225, 165, 0);}");
    }
}

void Lobby::updateLobbyStatus()
{
    updateLobbyId();
    updateActivePlayersNumber();
    updateLobbyPlayerListView();
    updateLobbyAdmin();
    hideOrShowStartGameButton();
}

void Lobby::updateLobbyId()
{
    int lobbyId = m_lobbyData.GetLobbyID();
    ui.lineEdit_viewLobbyId->setText(QString::number(lobbyId));
}

void Lobby::updateLobbyAdmin()
{
    QString adminUsername = "@" + QString::fromUtf8(m_lobbyData.GetLobbyAdmin().getUsername().c_str());
    for (int i = 0; i < ui.listWidget_players->count(); ++i)
    {
        QListWidgetItem* item = ui.listWidget_players->item(i);
        LobbyPlayerInfoWidget* playerWidget = qobject_cast<LobbyPlayerInfoWidget*>(ui.listWidget_players->itemWidget(item));
        if(playerWidget->getUsername()==adminUsername)
			playerWidget->updateAdminStatus(true);
		else
			playerWidget->updateAdminStatus(false);
    }
}

void Lobby::updateLobbyPlayerListView()
{
	ui.listWidget_players->clear();
	for (auto& player : m_lobbyData.GetUsers())
		addPlayerToLobbyListView(player);
}


void Lobby::on_pushButton_exitLobby_clicked()
{
    bool shouldClose = false;

    showConfirmActionCustomMessageBox(
        "Lobby - Leave lobby",
        "Are you sure you want to leave the lobby?",
        "Yes",
        "No",
        [&shouldClose]() {
            shouldClose = true;
        }
    );

    if (shouldClose)
    {
        emit goToJoinGameWindow();
        this->hide();
    }
}

void Lobby::on_pushButton_copyLobbyId_clicked()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(ui.lineEdit_viewLobbyId->text());
}

void Lobby::getLobbyData(const LobbyData& lobbyData)
{
    m_lobbyData = lobbyData;
	updateLobbyStatus();
}

void Lobby::on_pushButton_startGame_clicked()
{   
}
