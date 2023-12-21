#include "Login.h"

Login::Login(Contexts* contexts, QWidget *parent)
	: QMainWindow(parent),
    contexts(contexts)
{
    ui.setupUi(this);
}

Login::~Login()
{}

void Login::on_pushButton_goToRegister_clicked()
{
    emit windowPositionChanged(this->pos());
    emit goToRegister();
    this->hide();
}

void Login::on_pushButton_login_clicked()
{
    std::string username = ui.lineEdit_username->text().toUtf8().constData();
    std::string password = ui.lineEdit_password->text().toUtf8().constData();

    if (username.empty() || password.empty())
    {
        showErrorCustomMessageBox(
            "Gartic - Login",
            "One or more fields is empty. Please try again!",
            "Try Again",
            []() {}
        );
        return;
    }

    contexts->loginUser(username, password, [this](bool success, const std::string& message)
        {
            if (success)
            {
                showSuccessCustomMessageBox(
                    "Gartic - Login",
                    "Successful login. You can play now!",
                    "Play Now",
                    [this]() {
                        emit windowPositionChanged(this->pos());
                        emit goToJoinGame();
                        this->hide();
                    }
                );
            }
            else if (message == "Inexistent user")
            {
                showErrorCustomMessageBox(
                    "Gartic - Login",
                    "User doesn't exist. Please register!",
                    "Register now",
                    [this]() {
                        emit windowPositionChanged(this->pos());
                        emit goToRegister();
                        this->hide();
                    }
                );
            }
            else if (message == "Incorrect password")
            {
                showErrorCustomMessageBox(
                    "Gartic - Login",
                    "Password is incorrect. Please try again!",
                    "Try Again",
                    []() {
                    }
                );
            }
            else
            {
                showErrorCustomMessageBox(
                    "Gartic - Login",
                    "Something went wrong. Please try again later!",
                    "Ok",
                    []() {}
                );
            }
        });
}