#pragma once

#include <QWidget>
#include "ui_GamePlayerInfoWidget.h"

class GamePlayerInfoWidget : public QWidget
{
	Q_OBJECT

public:
	GamePlayerInfoWidget(QWidget* parent = nullptr);
	GamePlayerInfoWidget(const QString& username, const QString& surname, const QString& givenName, const int points, QWidget* parent = nullptr);
	~GamePlayerInfoWidget();
	QString getUsername() const;
	QString getPointsNumber() const;
	void updatePointsNumber(const int points);
	bool getIsDrawing() const;
	void updateIsDrawing(bool isDrawing);

private:
	Ui::GamePlayerInfoWidgetClass ui;
};
