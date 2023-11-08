#pragma once

#include <QMainWindow>
#include "ui_JoinGame.h"
#include "UserProfile.h"

class JoinGame : public QMainWindow
{
	Q_OBJECT

public:
	JoinGame(QWidget *parent = nullptr);
	~JoinGame();

private:
	Ui::JoinGameClass ui;
	UserProfile* userProfileWindow = nullptr;
	QString m_username;
signals:
	void loginWindow();
	void sendUsername(const QString&);
private slots:
	virtual void on_pushButton_userProfile_clicked();
public slots:
	virtual void getUsername(const QString&);

};
