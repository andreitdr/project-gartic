#pragma once

#include <QMainWindow>
#include "ui_GameWindow.h"
#include "../../Utils/GameData/GameData.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
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
	std::string wordToGuess;
	DisplayPaintWidget* displayWidget = nullptr;
	PaintWidget* paintWidget = nullptr;
	void leaveGame();
	void addPlayerToLeaderBoard(const UserInfo& userInfo, const int points, const bool isDrawing);
	void updateLeaderBoard();
	void updateTimer();
	void updateRoundNumber();
	void updateWordToGuess();
	void updateGameStatus();
	void updateGameData();

private slots:
	void on_pushButton_leaveGame_clicked();

signals:
	void windowPositionChanged(const QPoint& newPosition);
};
