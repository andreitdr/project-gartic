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
	updateActivePlayersNumber(ui.listWidget_players->count());
}


void Lobby::on_pushButton_exitLobby_clicked()
{
    removePlayerFromLobbyListView("test1");
    removePlayerFromLobbyListView("test5");
}

void Lobby::on_pushButton_startGame_clicked()
{
    addPlayerToLobbyListView("test1", "test1", "test1", true);
    addPlayerToLobbyListView("test2", "test2", "test2", false);
    addPlayerToLobbyListView("test3", "test3", "test3", false);
    addPlayerToLobbyListView("test4", "test4", "test4", false);
    addPlayerToLobbyListView("test5", "test5", "test5", false);
    addPlayerToLobbyListView("test6", "test6", "test6", false);
}
