#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Frontend.h"
#include "Register.h"
#include "JoinGame.h"
#include <qstring.h>
#include "CustomQtWidgets.h"

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

private slots:
    virtual void on_pushButton_goToRegister_clicked();
    void on_pushButton_login_clicked();

signals:
    void sendUsername(const QString&);
};
