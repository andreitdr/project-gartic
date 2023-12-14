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
