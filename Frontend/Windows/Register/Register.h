#pragma once

#include <QMainWindow>
#include "ui_Register.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private:
	Ui::RegisterClass ui;

private slots:
	void on_pushButton_register_clicked();
	void on_pushButton_goToLogin_clicked();
signals:
	void goToLogin();
};
