#pragma once

#include <QWidget>
#include "ui_UserProfile.h"
#include "../../Utils/UserInfo/UserInfo.h"

class UserProfile : public QWidget
{
	Q_OBJECT

public:
	UserProfile(QWidget *parent = nullptr);
	~UserProfile();

private:
	Ui::UserProfileClass ui;
	UserInfo m_user;

signals:
	void goToJoinGameWindow();
private slots:
	void on_pushButton_goBackUserProfile_clicked();
};
