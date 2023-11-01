#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Frontend.h"
#include "Register.h"
class Frontend : public QMainWindow
{
    Q_OBJECT

public:
    Frontend(QWidget *parent = nullptr);
    ~Frontend();

private:
    Ui::FrontendClass ui;
    Register* registerWindow;

private slots:
    virtual void on_pushButton_goToRegister_clicked();
};
