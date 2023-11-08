#include "Frontend.h"

Frontend::Frontend(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    registerWindow = new Register();
    connect(registerWindow, &Register::loginWindow, this, &Frontend::show);
    joinGameWindow = new JoinGame();
    connect(joinGameWindow, &JoinGame::loginWindow, this, &Frontend::show);
    connect(this, SIGNAL(sendUsername(const QString&)), joinGameWindow, SLOT(getUsername(const QString&)));
}

Frontend::~Frontend()
{}

void Frontend::on_pushButton_goToRegister_clicked()
{
    registerWindow->show();
    this->close();
}

void Frontend::on_pushButton_login_clicked()
{
    QString username = ui.lineEdit_username->text();
    QString password = ui.lineEdit_password->text();

    if(username=="\0"||password=="\0")
        showErrorCustomMessageBox(
            "Gartic - Login",
            "One or more fields is empty. Please try again!",
            "Try Again",
            []() {
            }
    );
    else
    //succesful login - to be linked with backend
        if (/*username == "1" &&*/ password == "1")
        {
            emit sendUsername(username);
            showSuccessCustomMessageBox(
                "Gartic - Login",
                "Successful login. You can play now!",
                "Play Now",
                [this, username]() {
                    joinGameWindow->show();
                    this->close();
                }
            );
        }
       
    else
        //if username doesn't exist - to be linked with backend
        if (username == "2" && password == "2")
            showErrorCustomMessageBox(
                "Gartic - Login",
                "User doesn't exist. Please register!",
                "Register now",
                [this]() {
                    registerWindow->show();
                    this->close();
                }
    );
        else
            //if password is incorect - to be linked with backend
            if (username == "3" && password == "3")
                showErrorCustomMessageBox(
                    "Gartic - Login",
                    "Password is incorrect. Please try again!",
                    "Try Again",
                    []() {
                    }
    );
            else
               showErrorCustomMessageBox(
                    "Gartic - Login",
                    "Something went wrong. Please try again later!",
                    "Ok",
                    []() {
                    }
    );
}

