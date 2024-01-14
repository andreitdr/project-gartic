#include "GameWindow.h"
#include <random>
#include <algorithm>
#include <set>
#include <regex>

GameWindow::GameWindow(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
    paintWidget = new PaintWidget();
    displayPaintWidget = new DisplayPaintWidget();

    m_drawingLayout = new QGridLayout();
    m_drawingLayout->addWidget(paintWidget);
    m_drawingLayout->addWidget(displayPaintWidget);

    ui.groupBox_drawing->setLayout(m_drawingLayout);

    paintWidget->setVisible(false);
    displayPaintWidget->setVisible(false);

    connect(ui.lineEdit_message, &QLineEdit::returnPressed, this, &GameWindow::on_pushButton_sendMessage_clicked);

    m_statusTimer = new QTimer(this);
    m_chatTimer = new QTimer(this);
    m_drawingTimer = new QTimer(this);

    connect(m_statusTimer, &QTimer::timeout, this, &GameWindow::updateGameData);
    connect(m_chatTimer, &QTimer::timeout, this, &GameWindow::updateChatData);
    connect(m_drawingTimer, &QTimer::timeout, this, &GameWindow::updateDrawing);
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
    else
        event->ignore();
}

void GameWindow::hideEvent(QHideEvent* event)
{
    QMainWindow::hideEvent(event);
    if (m_statusTimer && m_statusTimer->isActive())
        m_statusTimer->stop();

    if (m_chatTimer && m_chatTimer->isActive())
		m_chatTimer->stop();

	if (m_drawingTimer && m_drawingTimer->isActive())
		m_drawingTimer->stop();
}

void GameWindow::leaveGame()
{
    emit windowPositionChanged(this->pos());
    emit goToJoinGameWindow();
    this->hide();
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
    if (m_gameData.GetTimer() == 59)
    {
        paintWidget->clearImage();
        m_wordToGuess = std::string(m_gameData.GetCurrentWord().size(), '_');
        initializeRevealPositions(m_gameData.GetCurrentWord(), m_gameData.GetCurrentWord().size() / 2);
    }
}

void GameWindow::updateRoundNumber()
{
    QString roundNumber = QString::number(m_gameData.GetCurrentRound()/m_gameData.GetPlayers().size()+1);
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
        QString displayWord = QString::fromStdString(m_wordToGuess) + " (" + QString::number(currentWord.size()) + ")";
        ui.label_word->setText(displayWord);
        ui.label_guessDrawThis->setText("DRAW THIS");
        return;
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
        QString displayWord = QString::fromStdString(m_wordToGuess) + " (" + QString::number(currentWord.size()) + ")";
        ui.label_word->setText(displayWord);
        ui.label_guessDrawThis->setText("GUESS THIS");
    }

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
    bool isDrawingPlayer = (CurrentUser::getInstance().getUsername() == m_gameData.GetDrawingPlayer().getUsername());

    if (isDrawingPlayer)
    {
        paintWidget->setVisible(true);
        displayPaintWidget->setVisible(false);
        m_drawingLayout->setAlignment(paintWidget, Qt::AlignCenter);
    }
    else
    {
        paintWidget->setVisible(false);
        displayPaintWidget->setVisible(true);
        m_drawingLayout->setAlignment(displayPaintWidget, Qt::AlignCenter);
    }
}

void GameWindow::updateDrawing()
{
    if (CurrentUser::getInstance().getUsername() == m_gameData.GetDrawingPlayer().getUsername())
    {
        std::string drawing = m_imageConverter.convertImageToString(paintWidget->getImage());
        contexts->sendDrawing(m_gameData.GetGameId(), drawing, [this](bool success, const std::string& message){});
    }
    else
    {
        contexts->getDrawing(m_gameData.GetGameId(), [this](bool success, const std::string& message, const std::string& drawing)
			{
				if (success)
				{
                    QImage drawingImage = m_imageConverter.convertStringToImage(drawing);
                    displayPaintWidget->updateImage(drawingImage);
				}
			});
    }
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

bool GameWindow::containsOnlyWhitespace(const std::string& str)
{
    std::regex whitespaceRegex("^\\s*$");
    return std::regex_match(str, whitespaceRegex);
}

void GameWindow::updateChat()
{
	ui.listWidget_chat->clear();
    for (const auto& message : m_gameData.GetChatMessages())
    {
		addChatMessage(message);
	}
}

void GameWindow::updateChatData()
{
    contexts->getChatMessages(m_gameData.GetGameId(), [this](bool success, const std::string& message, const std::vector<std::string>& chatMessages)
		{
			if (success)
			{
				m_gameData.SetChatMessages(chatMessages);
				updateChat();
			}
		});
}

void GameWindow::updateGameData()
{
    contexts->getRunningGameStatus(m_gameData.GetGameId(), [this](bool success, const std::string& message, const GameData& gameData)
        {
            if (success)
            {
                if (!(gameData == m_gameData))
                {
                    m_gameData.SetDrawingPlayer(gameData.GetDrawingPlayer());
                    m_gameData.SetPlayers(gameData.GetPlayers());
                    m_gameData.SetCurrentRound(gameData.GetCurrentRound());
                    m_gameData.SetCurrentWord(gameData.GetCurrentWord());
                    m_gameData.SetTimer(gameData.GetTimer());
                    m_gameData.SetPlayerPoints(gameData.GetPlayerPoints());
                }
                updateGameStatus();
            }
        });
}

void GameWindow::on_pushButton_sendMessage_clicked()
{
    std::string message = ui.lineEdit_message->text().toUtf8().constData();
    if (message.empty()||containsOnlyWhitespace(message))
    {
        showErrorCustomMessageBox(
            this,
            "Gartic - Game",
            "You can't send an empty message!",
            "Ok",
            []() {}
        );
        return;
    }
       
    contexts->checkWord(m_gameData.GetGameId(), CurrentUser::getInstance().getUserId(), message, [this](bool success, const std::string& message)
		{
            if (success)
            {
                ui.lineEdit_message->clear();
            }
            else
            {
                QString qmessage = QString::fromUtf8(message.c_str());
                showErrorCustomMessageBox(
                    this,
                    "Gartic - Game",
                    qmessage,
                    "Ok",
                    []() {}
                );
            }
		});
}

void GameWindow::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);
    if (m_statusTimer && !m_statusTimer->isActive())
        m_statusTimer->start(500);

    if (m_chatTimer && !m_chatTimer->isActive())
		m_chatTimer->start(500);

	if (m_drawingTimer && !m_drawingTimer->isActive())
		m_drawingTimer->start(250);
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

void GameWindow::getGameId(const int gameId)
{
    m_gameData.SetGameId(gameId);
}