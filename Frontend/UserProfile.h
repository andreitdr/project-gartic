#pragma once

#include <QWidget>
#include "ui_UserProfile.h"

class UserProfile : public QWidget
{
	Q_OBJECT

public:
	UserProfile(QWidget *parent = nullptr);
	~UserProfile();

private:
	Ui::UserProfileClass ui;
};
