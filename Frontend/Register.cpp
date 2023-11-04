#include "Register.h"
#include <qmessagebox.h>
Register::Register(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Register::~Register()
{}

void Register::on_pushButton_goToLogin_clicked()
{
	this->hide();
	QWidget* parent = this->parentWidget();
	parent->show();
}

void Register::on_pushButton_register_clicked()
{
	QMessageBox::information(this, "Register", "Register");
}