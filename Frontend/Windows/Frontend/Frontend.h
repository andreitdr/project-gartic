#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Frontend.h"
#include "../../Windows/Register/Register.h"
#include "../../Windows/JoinGame/JoinGame.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"
#include "../../Utils/UserInfo/UserInfo.h"
#include "../../API/Requests/Requests.h"
#include "../../API/ResponseHandler/ResponseHandler.h"
#include <qstring.h>

class Frontend : public QMainWindow
{
    Q_OBJECT

public:
    Frontend(QWidget *parent = nullptr);
    ~Frontend();

private:
    Ui::FrontendClass ui;
    Register* registerWindow = nullptr;
    JoinGame* joinGameWindow = nullptr;
    UserInfo m_user;

private slots:
    virtual void on_pushButton_goToRegister_clicked();
    void on_pushButton_login_clicked();

signals:
    void sendUser(const UserInfo&);
};
