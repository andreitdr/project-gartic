#include "LobbySettings.h"

LobbySettings::LobbySettings(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
	contexts(contexts)
{
	ui.setupUi(this);
}

LobbySettings::~LobbySettings()
{}

void LobbySettings::on_pushButton_saveSettings_clicked()
{
	bool isPrivate;
	int gameMode;
	if(ui.radioButton_VisibilityPrivate->isChecked())
	isPrivate = true;
	else
		isPrivate = false;

	if (ui.radioButton_GameMode1->isChecked())
		gameMode = 1;
	else if (ui.radioButton_GameMode2->isChecked())
		gameMode = 2;
	emit updateSettings(isPrivate, gameMode);
	emit windowPositionChanged(this->pos());
	this->hide();
}