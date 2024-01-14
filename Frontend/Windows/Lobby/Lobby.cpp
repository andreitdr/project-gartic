#include "Lobby.h"

Lobby::Lobby(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
    contexts(contexts)
{
	ui.setupUi(this);
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Lobby::updateLobbyData);
}

Lobby::~Lobby()
{}

void Lobby::closeEvent(QCloseEvent * event)
{
    bool shouldClose = false;

   showConfirmActionCustomMessageBox(
       this,
        "Lobby - Leave lobby",
        "Are you sure you want to leave the lobby?",
        "Yes",
        "No",
        [&shouldClose]() {
            shouldClose = true;
        }
    );

    if (shouldClose)
        leaveLobby();
    else 
        event->ignore();
}

void Lobby::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);
    if (m_timer && !m_timer->isActive())
        m_timer->start(500);
}

void Lobby::hideEvent(QHideEvent* event)
{
    QMainWindow::hideEvent(event);
    if (m_timer && m_timer->isActive())
        m_timer->stop();
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

    if(CurrentUser::getInstance().getUsername() != m_lobbyData.GetLobbyAdmin().getUsername())
    updateSettingsStatus();

    gameStarted();
}

void Lobby::updateSettingsStatus()
{
    if (m_lobbyData.GetIsPrivate())
        ui.radioButton_Private->setChecked(true);
    else
        ui.radioButton_Public->setChecked(true);
    if (m_lobbyData.GetLobbyType() == 1)
        ui.radioButton_GuessingMode->setChecked(true);
    else
        ui.radioButton_DrawingContest->setChecked(true);
}

void Lobby::leaveLobby()
{
    int lobbyId = m_lobbyData.GetLobbyID();
    int userId = CurrentUser::getInstance().getUserId();
    contexts->leaveLobby(userId, lobbyId, [this](bool success, const std::string& message) {
        if (success) {
            emit windowPositionChanged(this->pos());
			emit goToJoinGameWindow();
			this->hide();
		}
        else {
            showErrorCustomMessageBox(
                this,
                "Gartic - Leave Lobby",
                "Something went wrong. Please try again later!",
                "Ok",
                []() {}
            );
		}
	});
}

void Lobby::updateLobbyData()
{
    int lobbyId = m_lobbyData.GetLobbyID();
    contexts->lobbyStatus(lobbyId, [this](bool success, const std::string& message, const LobbyData& lobbyData) {
        if (success) {
            if(!(lobbyData==m_lobbyData))
			m_lobbyData = lobbyData;
			updateLobbyStatus();
		}
	});
}

void Lobby::gameStarted()
{
    if (m_lobbyData.GetIsStarted())
    {
        emit sendGameId(1);
        //apelare ruta
    }
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
        this,
        "Lobby - Leave lobby",
        "Are you sure you want to leave the lobby?",
        "Yes",
        "No",
        [&shouldClose]() {
            shouldClose = true;
        }
    );

    if (shouldClose)
        leaveLobby();
}

void Lobby::on_pushButton_copyLobbyId_clicked()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(ui.lineEdit_viewLobbyId->text());
}

void Lobby::on_pushButton_lobbySettings_clicked()
{
	ui.groupBox_lobbyStatus->hide();
    ui.groupBox_lobbySettings->show();
    updateSettingsStatus();

    bool isAdmin = m_lobbyData.GetLobbyAdmin().getUsername() == CurrentUser::getInstance().getUsername();

    if (!isAdmin)
    {
        ui.pushButton_saveSettings->hide();
        ui.pushButton_goBackSettings->show();
        ui.radioButton_Private->setFocusPolicy(Qt::NoFocus);
        ui.radioButton_Private->setAttribute(Qt::WA_TransparentForMouseEvents);
        ui.radioButton_Public->setFocusPolicy(Qt::NoFocus);
        ui.radioButton_Public->setAttribute(Qt::WA_TransparentForMouseEvents);
        ui.radioButton_GuessingMode->setFocusPolicy(Qt::NoFocus);
        ui.radioButton_GuessingMode->setAttribute(Qt::WA_TransparentForMouseEvents);
        ui.radioButton_DrawingContest->setFocusPolicy(Qt::NoFocus);
        ui.radioButton_DrawingContest->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
    else
    {
        ui.pushButton_saveSettings->show();
        ui.pushButton_goBackSettings->hide();
        ui.radioButton_Private->setFocusPolicy(Qt::StrongFocus);
        ui.radioButton_Private->setAttribute(Qt::WA_TransparentForMouseEvents, false);
        ui.radioButton_Public->setFocusPolicy(Qt::StrongFocus);
        ui.radioButton_Public->setAttribute(Qt::WA_TransparentForMouseEvents, false);
        ui.radioButton_GuessingMode->setFocusPolicy(Qt::StrongFocus);
        ui.radioButton_GuessingMode->setAttribute(Qt::WA_TransparentForMouseEvents, false);
        ui.radioButton_DrawingContest->setFocusPolicy(Qt::StrongFocus);
        ui.radioButton_DrawingContest->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    }
}

void Lobby::on_pushButton_saveSettings_clicked()
{
        if (ui.radioButton_Private->isChecked())
            m_lobbyData.SetIsPrivate(true);
        else
            if (ui.radioButton_Public->isChecked())
                m_lobbyData.SetIsPrivate(false);

        if (ui.radioButton_GuessingMode->isChecked())
            m_lobbyData.SetLobbyType(1);
        else
            if (ui.radioButton_DrawingContest->isChecked())
                m_lobbyData.SetLobbyType(2);

        contexts->updateLobby(m_lobbyData.GetLobbyID(), m_lobbyData.GetLobbyType(), m_lobbyData.GetIsPrivate(), [this](bool success, const std::string& message) {
            if (success) {
                ui.groupBox_lobbySettings->hide();
                ui.groupBox_lobbyStatus->show();
            }
            else {
                showErrorCustomMessageBox(
                    this,
                    "Gartic - Lobby Settings",
                    "Something went wrong. Please try again later!",
                    "Ok",
                    []() {}
                );
            }
            });
}

void Lobby::on_pushButton_goBackSettings_clicked()
{
    ui.groupBox_lobbySettings->hide();
	ui.groupBox_lobbyStatus->show();
}

void Lobby::getLobbyId(int lobbyId)
{
    m_lobbyData.SetLobbyID(lobbyId);
    updateLobbyStatus();
}

void Lobby::getLobbyData(const LobbyData& lobbyData)
{
    m_lobbyData = lobbyData;
	updateLobbyStatus();
}

void Lobby::on_pushButton_startGame_clicked()
{   
    contexts->startGame(m_lobbyData.GetLobbyID(), [this](bool success, const std::string& message, int gameId) {
        QString qmessage = QString::fromUtf8(message.c_str());
		if (success) {
			emit sendGameId(gameId);
            emit windowPositionChanged(this->pos());
            emit goToGameWindow();
            this->hide();
		}
        else
        if (message != "")
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
				"Gartic - Start Game",
				"Something went wrong. Please try again later!",
				"Ok",
				[]() {}
			);
		}
		});
}
