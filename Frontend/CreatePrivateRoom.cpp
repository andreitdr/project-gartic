#include "CreatePrivateRoom.h"

CreatePrivateRoom::CreatePrivateRoom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CreatePrivateRoom::~CreatePrivateRoom()
{}

void CreatePrivateRoom::on_pushButton_copyCode_clicked()
{
	QLineEdit* viewCodeLineEdit = findChild<QLineEdit*>("lineEdit_viewCode");
	QString code = viewCodeLineEdit->text();
	QClipboard* clipboard = QApplication::clipboard();
	clipboard->setText(code);
}

void CreatePrivateRoom::on_pushButton_generateCode_clicked()
{
	QString code = "234943";//to be obtained from backend
	QLineEdit* viewCodeLineEdit = findChild<QLineEdit*>("lineEdit_viewCode");
	viewCodeLineEdit->setText(code);
}

void CreatePrivateRoom::on_pushButton_goBack_clicked()
{
	emit joinGameWindow();
	this->hide();
}