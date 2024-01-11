#include "GameWindow.h"

GameWindow::GameWindow(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
}

GameWindow::~GameWindow()
{}

void GameWindow::closeEvent(QCloseEvent * event)
{
}

void GameWindow::hideEvent(QHideEvent* event)
{
}

void showEGameWindow::vent(QShowEvent* event)
{
	return void showE();
}

void GameWindow::on_pushButton_leaveGame_clicked()
{

}