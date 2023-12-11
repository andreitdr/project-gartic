#include "Lobby.h"

Lobby::Lobby(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Lobby::~Lobby()
{}

void Lobby::updateActivePlayersNumber(int playerNumber)
{
	ui.label_playersActiveNumber->setText(QString::number(playerNumber));
}

void Lobby::addPlayerToLobbyListView(const QString& username, const QString& surname, const QString& givenName, bool isAdmin) {
	QListWidgetItem* item = new QListWidgetItem(ui.listWidget_players);
	LobbyPlayerInfoWidget* playerWidget = new LobbyPlayerInfoWidget(username, surname, givenName, isAdmin);

	const QSize fixedSize = QSize(281,80); 
	item->setSizeHint(fixedSize);

	ui.listWidget_players->setItemWidget(item, playerWidget);
    hideOrShowStartGameButton();
	updateActivePlayersNumber(ui.listWidget_players->count());
}

void Lobby::removePlayerFromLobbyListView(const QString& username)
{
    int indexToRemove = -1;

    for (int i = 0; i < ui.listWidget_players->count(); ++i) {
        QListWidgetItem* item = ui.listWidget_players->item(i);
        LobbyPlayerInfoWidget* playerWidget = qobject_cast<LobbyPlayerInfoWidget*>(ui.listWidget_players->itemWidget(item));

		QString tempUsername="@"+username;
        if (playerWidget->getUsername() == tempUsername) {
                indexToRemove = i;
                break;
            }
    }

    if (indexToRemove != -1) {
        QListWidgetItem* itemToRemove = ui.listWidget_players->takeItem(indexToRemove);
        delete itemToRemove;
    }
    hideOrShowStartGameButton();
	updateActivePlayersNumber(ui.listWidget_players->count());
}

void Lobby::hideOrShowStartGameButton()
{
    if((m_lobbyData.GetLobbyAdmin().getUsername()!=m_user.getUsername())||(ui.listWidget_players->count()==1))
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

void Lobby::updateLobbyId(int lobbyId)
{
    ui.lineEdit_viewLobbyId->setText(QString::number(lobbyId));
}


void Lobby::on_pushButton_exitLobby_clicked()
{
    removePlayerFromLobbyListView("test1");
    removePlayerFromLobbyListView("test5");

}

void Lobby::on_pushButton_copyLobbyId_clicked()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(ui.lineEdit_viewLobbyId->text());
}

void Lobby::on_pushButton_startGame_clicked()
{
    updateLobbyId(8832131);
    addPlayerToLobbyListView("test1", "test1", "test1", true);
    addPlayerToLobbyListView("test2", "test2", "test2", false);
    addPlayerToLobbyListView("test3", "test3", "test3", false);
    addPlayerToLobbyListView("test4", "test4", "test4", false);
    addPlayerToLobbyListView("test5", "test5", "test5", false);
    addPlayerToLobbyListView("test6", "test6", "test6", false);
}
