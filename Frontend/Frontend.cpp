#include "Frontend.h"

Frontend::Frontend(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Frontend::~Frontend()
{}

void Frontend::on_pushButton_goToRegister_clicked()
{
    this->close();
    registerWindow = new Register(this);
    registerWindow->show();
}
