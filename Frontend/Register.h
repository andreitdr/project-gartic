#pragma once

#include <QMainWindow>
#include "ui_Register.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private:
	Ui::RegisterClass ui;

private slots:
	virtual void on_pushButton_register_clicked();
	virtual void on_pushButton_goToLogin_clicked();
	
};
