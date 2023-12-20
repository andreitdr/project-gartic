#pragma once

#include <QMainWindow>
#include "ui_UserProfile.h"

class UserProfile : public QMainWindow
{
	Q_OBJECT

public:
	UserProfile(QWidget *parent = nullptr);
	~UserProfile();

protected:
	void showEvent(QShowEvent* event) override;

private:
	Ui::UserProfileClass ui;
	void updateUserInfoDisplay();

signals:
	void goToJoinGameWindow();
private slots:
	void on_pushButton_goBackUserProfile_clicked();
};
