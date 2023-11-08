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
	QString m_username;

signals:
	void joinGameWindow();
private slots:
	virtual void on_pushButton_goBackUserProfile_clicked();
public slots:
	virtual void getUsername(const QString&);
};
