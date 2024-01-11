#pragma once

#include <QMainWindow>
#include "ui_GameWindow.h"
#include "../../Widgets/DisplayPaintWidget/DisplayPaintWidget.h"
#include "../../Widgets/PaintWidget/PaintWidget.h"
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
	DisplayPaintWidget* displayWidget = nullptr;
	PaintWidget* paintWidget = nullptr;

private slots:
	void on_pushButton_leaveGame_clicked();

signals:
	void windowPositionChanged(const QPoint& newPosition);
};
