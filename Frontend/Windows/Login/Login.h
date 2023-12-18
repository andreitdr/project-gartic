#pragma once

#include <QMainWindow>
#include "ui_Login.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../API/Requests/Requests.h"
#include "../../API/ResponseHandler/ResponseHandler.h"
#include <qstring.h>

class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

private:
	Ui::LoginClass ui;

private slots:
	void on_pushButton_goToRegister_clicked();
	void on_pushButton_login_clicked();

signals:
	void goToRegister();
	void goToJoinGame();
};
