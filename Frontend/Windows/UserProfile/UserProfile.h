#pragma once

#include <QMainWindow>
#include "ui_UserProfile.h"
#include "../../API/Contexts/Contexts.h"

class UserProfile : public QMainWindow
{
	Q_OBJECT

public:
	explicit UserProfile(Contexts* contexts, QWidget *parent = nullptr);
	~UserProfile();

protected:
	void showEvent(QShowEvent* event) override;

private:
	Ui::UserProfileClass ui;
	Contexts* contexts;
	void updateUserInfoDisplay();

signals:
	void goToJoinGameWindow();
	void windowPositionChanged(const QPoint& newPosition);
private slots:
	void on_pushButton_goBackUserProfile_clicked();
};
