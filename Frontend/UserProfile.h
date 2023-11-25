#pragma once

#include <QWidget>
#include "ui_UserProfile.h"
#include "UserInfo.h"

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
	void joinGameWindow();
private slots:
	virtual void on_pushButton_goBackUserProfile_clicked();
public slots:
	virtual void getUser(const UserInfo&);
};
