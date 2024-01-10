#pragma once

#include <QMainWindow>
#include "ui_LobbySettings.h"
#include "../../API/Contexts/Contexts.h"

class LobbySettings : public QMainWindow
{
	Q_OBJECT

public:
	LobbySettings(Contexts* contexts, QWidget *parent = nullptr);
	~LobbySettings();

private:
	Contexts* contexts;
	Ui::LobbySettingsClass ui;

private slots:
	void on_pushButton_saveSettings_clicked();

signals:
	void updateSettings(bool isPrivate, int gameMode);
	void windowPositionChanged(const QPoint& newPosition);
};
