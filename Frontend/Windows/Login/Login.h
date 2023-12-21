#pragma once

#include <QMainWindow>
#include "ui_Login.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include <qstring.h>
#include "../../API/Contexts/Contexts.h"

class Login : public QMainWindow
{
	Q_OBJECT

public:
	explicit Login(Contexts* contexts, QWidget *parent = nullptr);
	~Login();

private:
	Ui::LoginClass ui;
	Contexts* contexts;

private slots:
	void on_pushButton_goToRegister_clicked();
	void on_pushButton_login_clicked();

signals:
	void goToRegister();
	void goToJoinGame();
};
