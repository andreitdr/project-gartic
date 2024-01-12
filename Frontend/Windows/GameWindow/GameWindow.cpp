#include "GameWindow.h"
#include <random>
#include <algorithm>
#include <set>

GameWindow::GameWindow(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
    paintWidget = new PaintWidget();
    displayPaintWidget = new DisplayPaintWidget();
    connect(ui.lineEdit_message, &QLineEdit::returnPressed, this, &GameWindow::on_pushButton_sendMessage_clicked);
}

GameWindow::~GameWindow()
{
    delete paintWidget;
    delete displayPaintWidget;
}

void GameWindow::closeEvent(QCloseEvent * event)
{
    bool shouldClose = false;

    showConfirmActionCustomMessageBox(
        this,
        "Gartic - Leave Gane",
        "Are you sure you want to leave the game?",
        "Yes",
        "No",
        [&shouldClose]() {
            shouldClose = true;
        }
    );

    if (shouldClose)
        leaveGame();
    else
        event->ignore();
}

void GameWindow::hideEvent(QHideEvent* event)
{
    //timers stop
}

void GameWindow::leaveGame()
{
    //leave game route
}

void GameWindow::addPlayerToLeaderBoard(const UserInfo& userInfo, const int points, const bool isDrawing)
{
    QListWidgetItem* item = new QListWidgetItem(ui.listWidget_playerList);
    QString username = QString::fromUtf8(userInfo.getUsername().c_str());
    QString surname = QString::fromUtf8(userInfo.getSurname().c_str());
    QString givenName = QString::fromUtf8(userInfo.getGivenName().c_str());
    GamePlayerInfoWidget* playerWidget = new GamePlayerInfoWidget(username, surname, givenName, points);

    playerWidget->updateIsDrawing(isDrawing);

    const QSize fixedSize = QSize(241, 80);
    item->setSizeHint(fixedSize);

    ui.listWidget_playerList->setItemWidget(item, playerWidget);
}

void GameWindow::updateLeaderBoard()
{
    m_gameData.SortPlayersByPoints();
    ui.listWidget_playerList->clear();
    for (const auto& player : m_gameData.GetPlayers())
    {
        int points = m_gameData.GetPlayerPoints(player.getUserId());
        bool isDrawing = player.getUserId() == m_gameData.GetDrawingPlayer().getUserId();
        addPlayerToLeaderBoard(player, points, isDrawing);
    }
}

void GameWindow::updateTimer()
{
    ui.label_timerNumber->setText(QString::number(m_gameData.GetTimer()));
    if (m_gameData.GetTimer() == 60)
    {
        initializeRevealPositions(m_gameData.GetCurrentWord(), m_gameData.GetCurrentWord().size() / 2);
        m_wordToGuess = std::string(m_gameData.GetCurrentWord().size(), '_');
    }
}

void GameWindow::updateRoundNumber()
{
    QString roundNumber = QString::number(m_gameData.GetCurrentRound());
    QString temp = "Round " + roundNumber + " of 4";
    ui.label_roundNumber->setText(temp);
}

void GameWindow::initializeRevealPositions(const std::string& word, int maxReveal)
{
    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, word.size() - 1);

	std::set<int> positions;
    while (positions.size() < maxReveal)
    {
		positions.insert(dis(gen));
	}

    m_revealedPositions.clear();
    for (const auto& pos : positions)
    {
        m_revealedPositions.push_back(pos);
	}
}

void GameWindow::updateWordToGuess()
{
    const std::string& currentWord = m_gameData.GetCurrentWord();
    int timeRemaining = m_gameData.GetTimer();

    if (CurrentUser::getInstance().getUsername() == m_gameData.GetDrawingPlayer().getUsername()) {
        m_wordToGuess = currentWord;
    }
    else {
        int lettersToRevealNow = 0;
        if (timeRemaining <= 10) {
            lettersToRevealNow = m_revealedPositions.size();
        }
        else if (timeRemaining <= 20) {
            lettersToRevealNow = m_revealedPositions.size() / 2;
        }
        else if (timeRemaining <= 30) {
            lettersToRevealNow = m_revealedPositions.size() / 3;
        }

        for (int i = 0; i < lettersToRevealNow; ++i) {
            int pos = m_revealedPositions[i];
           m_wordToGuess[pos] = currentWord[pos];
        }
    }

    QString displayWord = QString::fromStdString(m_wordToGuess) + " (" + QString::number(currentWord.size()) + ")";
    ui.label_word->setText(displayWord);
    ui.label_guessDrawThis->setText("GUESS THIS");
}

void GameWindow::updateGameStatus()
{
	updateTimer();
	updateRoundNumber();
    updateLeaderBoard();
    updateWordToGuess();
    updateDrawingWidget();
    updateChat();
}

void GameWindow::updateDrawingWidget()
{
    QGridLayout* layout = new QGridLayout();
    if (CurrentUser::getInstance().getUsername() == m_gameData.GetDrawingPlayer().getUsername())
    {
		layout->addWidget(paintWidget);
        layout->setAlignment(paintWidget, Qt::AlignTop);
    }
    else
    {
		layout->addWidget(displayPaintWidget);
        layout->setAlignment(displayPaintWidget, Qt::AlignTop);
    }
    layout->setContentsMargins(2, 2, 2, 2);
    ui.groupBox_drawing->setLayout(layout);
}

void GameWindow::addChatMessage(const std::string& message)
{
   QString messageText = QString::fromUtf8(message.c_str());
    QListWidgetItem *newItem = new QListWidgetItem(messageText);
    
    if (messageText.contains("guessed the word"))
    {
        newItem->setForeground(QBrush(Qt::darkGreen));
    }
    
    ui.listWidget_chat->addItem(newItem);
}

void GameWindow::updateChat()
{
	ui.listWidget_chat->clear();
    for (const auto& message : m_gameData.GetChatMessages())
    {
		addChatMessage(message);
	}
}

void GameWindow::updateGameData()
{
    //apelare ruta
    updateGameStatus();
}

void GameWindow::on_pushButton_sendMessage_clicked()
{
    std::string message = ui.lineEdit_message->text().toUtf8().constData();
    //apelare ruta
    addChatMessage(message);
    ui.lineEdit_message->clear();
}

void GameWindow::showEvent(QShowEvent* event)
{
    //timers start
}

void GameWindow::on_pushButton_leaveGame_clicked()
{
    bool shouldClose = false;

    showConfirmActionCustomMessageBox(
        this,
        "Gartic - Leave Game",
        "Are you sure you want to leave the game?",
        "Yes",
        "No",
        [&shouldClose]() {
            shouldClose = true;
        }
    );

    if (shouldClose)
        leaveGame();
}