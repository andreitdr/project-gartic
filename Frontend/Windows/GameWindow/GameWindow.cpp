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
    if(m_gameData.GetTimer() == 60)
        wordToGuess = std::string(m_gameData.GetCurrentWord().size(), '_');
}

void GameWindow::updateRoundNumber()
{
    QString roundNumber = QString::number(m_gameData.GetCurrentRound());
    QString temp = "Round " + roundNumber + " of 4";
    ui.label_roundNumber->setText(temp);
}

void GameWindow::updateWordToGuess()
{
    const std::string& currentWord = m_gameData.GetCurrentWord();
    int timeRemaining = m_gameData.GetTimer();

    if (CurrentUser::getInstance().getUsername() == m_gameData.GetDrawingPlayer().getUsername()) {
        wordToGuess = currentWord;
        ui.label_word->setText(QString::fromUtf8(wordToGuess.c_str()) + " (" + QString::number(currentWord.size()) + ")");
        ui.label_guessDrawThis->setText("DRAW THIS");
        return;
    }

    int maxLettersToReveal = currentWord.size() / 2;
    int lettersToRevealNow = 0;
    if (timeRemaining <= 10) {
        lettersToRevealNow = maxLettersToReveal;
    }
    else if (timeRemaining <= 20) {
        lettersToRevealNow = maxLettersToReveal / 2;
    }
    else if (timeRemaining <= 30) {
        lettersToRevealNow = maxLettersToReveal / 3;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, currentWord.size() - 1);

    while (lettersToRevealNow > 0) {
        int pos = dis(gen);
        if (wordToGuess[pos] == '_') {
            wordToGuess[pos] = currentWord[pos];
            lettersToRevealNow--;
        }
    }

    QString wordToGuess = QString::fromUtf8(this->wordToGuess.c_str());
    QString tempWord = wordToGuess + " (" + QString::number(currentWord.size()) + ")";
    ui.label_word->setText(tempWord);
    ui.label_guessDrawThis->setText("GUESS THIS");
}

void GameWindow::updateGameStatus()
{
	updateTimer();
	updateRoundNumber();
    updateLeaderBoard();
    updateWordToGuess();
    updateDrawingWidget();
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

void GameWindow::updateGameData()
{
    //apelare ruta
    updateGameStatus();
}

void GameWindow::showEvent(QShowEvent* event)
{
    //timers start
}

void GameWindow::on_pushButton_leaveGame_clicked()
{
    /*bool shouldClose = false;

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
        leaveGame();*/
    m_gameData.SetTimer(5);
    m_gameData.SetCurrentRound(2);
    m_gameData.SetCurrentWord("cuvantul");
    wordToGuess = std::string(m_gameData.GetCurrentWord().size(), '_');
    UserInfo player1 = UserInfo("user1", "user1", "user1", 1);
    UserInfo player2 = UserInfo("user2", "user2", "user2", 2);
    UserInfo player3 = UserInfo("user3", "user3", "user3", 3);
    UserInfo player4 = UserInfo("user4", "user4", "user4", 4);
    CurrentUser::getInstance().setUsername("user1");
    m_gameData.SetDrawingPlayer(player1);
    m_gameData.SetPlayerPoints(player1.getUserId(), 100);
    m_gameData.SetPlayerPoints(player2.getUserId(), 200);
    m_gameData.SetPlayerPoints(player3.getUserId(), 500);
    m_gameData.SetPlayerPoints(player4.getUserId(), 400);
    m_gameData.AddPlayer(player1);
    m_gameData.AddPlayer(player2);
    m_gameData.AddPlayer(player3);
    m_gameData.AddPlayer(player4);
    updateGameData();
}