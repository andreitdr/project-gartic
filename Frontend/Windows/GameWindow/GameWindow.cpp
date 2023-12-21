#include "GameWindow.h"

GameWindow::GameWindow(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
}

GameWindow::~GameWindow()
{}