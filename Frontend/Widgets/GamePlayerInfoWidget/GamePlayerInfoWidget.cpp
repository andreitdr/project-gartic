#include "GamePlayerInfoWidget.h"

GamePlayerInfoWidget::GamePlayerInfoWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label_avatarBackgroundDrawing->hide();
}

GamePlayerInfoWidget::GamePlayerInfoWidget(const QString& username, const QString& surname, const QString& givenName, const int points, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label_avatarBackgroundDrawing->hide();
	QString tempUsername = "@" + username;
	ui.label_username->setText(tempUsername);
	QString tempName = givenName + " " + surname;
	ui.label_surnameGivenName->setText(tempName);
	QString avatarLetter = givenName[0].toUpper();
	ui.label_avatarLetter->setText(avatarLetter);
	QString pointsString = QString::number(points) + " points";
	ui.label_pointsNumber->setText(pointsString);
}

GamePlayerInfoWidget::~GamePlayerInfoWidget()
{}

QString GamePlayerInfoWidget::getUsername() const
{
	return ui.label_username->text();
}

QString GamePlayerInfoWidget::getPointsNumber() const
{
	return ui.label_pointsNumber->text();
}

void GamePlayerInfoWidget::updatePointsNumber(const int points)
{
	QString pointsString = QString::number(points) + " points";
	ui.label_pointsNumber->setText(pointsString);
}

bool GamePlayerInfoWidget::getIsDrawing() const
{
	return ui.label_avatarBackgroundDrawing->isVisible();
}

void GamePlayerInfoWidget::updateIsDrawing(bool isDrawing)
{
	if (isDrawing)
	{
		ui.label_avatarBackgroundDrawing->show();
		ui.label_avatarBackground->hide();

	}
	else
	{
		ui.label_avatarBackgroundDrawing->hide();
		ui.label_avatarBackground->show();
	}
}


