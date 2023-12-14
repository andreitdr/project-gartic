#pragma once

#include <QMainWindow>
#include "ui_Login.h"
#include "../../Windows/Register/Register.h"
#include "../../Windows/JoinGame/JoinGame.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Utils/UserInfo/UserInfo.h"
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
	Register* registerWindow = nullptr;
	JoinGame* joinGameWindow = nullptr;
	UserInfo m_user;

private slots:
	virtual void on_pushButton_goToRegister_clicked();
	void on_pushButton_login_clicked();

signals:
	void sendUser(const UserInfo&);
};
