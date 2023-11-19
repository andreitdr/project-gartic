#pragma once

#include <QMainWindow>
#include "ui_GameWindow.h"
#include "DisplayPaintWidget.h"
#include "PaintWidget.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QWidget *parent = nullptr);
	~GameWindow();

private:
	Ui::GameWindowClass ui;
	DisplayPaintWidget* displayWidget = nullptr;
	PaintWidget* paintWidget = nullptr;
};
