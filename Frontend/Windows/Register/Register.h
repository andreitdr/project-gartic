#pragma once
#include "../../API/Contexts/Contexts.h"
#include <QMainWindow>
#include "ui_Register.h"
#include "../../Widgets/CustomQMessageBox/CustomQMessageBox.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	explicit Register(Contexts* contexts, QWidget *parent = nullptr);
	~Register();

private:
	Ui::RegisterClass ui;
	Contexts* contexts;
	bool validateName(const std::string& name);
	bool validateUsername(const std::string& username);
	bool validatePassword(const std::string& password);

private slots:
	void on_pushButton_register_clicked();
	void on_pushButton_goToLogin_clicked();
signals:
	void goToLogin();
	void windowPositionChanged(const QPoint& newPosition);
};
