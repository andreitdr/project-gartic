#pragma once

#include <QMainWindow>
#include <QTimer>
#include "ui_GameWindow.h"
#include "../../Utils/GameData/GameData.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../Utils/QImageConverter/QImageConverter.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Widgets/DisplayPaintWidget/DisplayPaintWidget.h"
#include "../../Widgets/PaintWidget/PaintWidget.h"
#include "../../Widgets/GamePlayerInfoWidget/GamePlayerInfoWidget.h"
#include "../../API/Contexts/Contexts.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit GameWindow(Contexts* contexts, QWidget *parent = nullptr);
	~GameWindow();

protected:
	void closeEvent(QCloseEvent* event) override;
	void showEvent(QShowEvent* event) override;
	void hideEvent(QHideEvent* event) override;

private:
	Ui::GameWindowClass ui;
	Contexts* contexts;
	GameData m_gameData;
	QImageConverter m_imageConverter;
	std::string m_wordToGuess;
	std::vector<int> m_revealedPositions;
	DisplayPaintWidget* displayPaintWidget = nullptr;
	PaintWidget* paintWidget = nullptr;
	QTimer* m_statusTimer = nullptr;
	QTimer* m_chatTimer = nullptr;
	QTimer* m_drawingTimer = nullptr;
	void leaveGame();
	void addPlayerToLeaderBoard(const UserInfo& userInfo, const int points, const bool isDrawing);
	void updateLeaderBoard();
	void updateTimer();
	void updateRoundNumber();
	void initializeRevealPositions(const std::string& word, int maxReveal);
	void updateWordToGuess();
	void updateGameStatus();
	void updateGameData();
	void updateDrawingWidget();
	void addChatMessage(const std::string& message);
	bool containsOnlyWhitespace(const std::string& str);
	void updateChat();
	void updateChatData();
	void updateDrawing();

private slots:
	void on_pushButton_leaveGame_clicked();
	void on_pushButton_sendMessage_clicked();

public slots:
	void getGameId(const int gameId);

signals:
	void goToJoinGameWindow();
	void windowPositionChanged(const QPoint& newPosition);
};
