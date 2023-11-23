﻿#include "Frontend.h"
#include "Requests.h"

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
    QString temp_username = ui.lineEdit_username->text();
    QString temp_password = ui.lineEdit_password->text();
    std::string username = temp_username.toUtf8().constData();
    std::string password = temp_password.toUtf8().constData();

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

    auto response = Requests::LoginUser(username, password);
    if (response.status_code == 200)
    {
        auto response_json = crow::json::load(response.text);
        if (!response_json)
        {
            showErrorCustomMessageBox(
                "Gartic - Login",
                "Something went wrong. Please try again later!",
                "Ok",
                []() {}
            );
            return;
        }
        else
        {
            bool success_state = response_json["ResponseState"].b();
            std::string response_message = response_json["ResponseMessage"][0].s();
            if (response_message == "Success")
            {
                emit sendUsername(temp_username);
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
            else if (response_message == "Inexistent user")
            {
                showErrorCustomMessageBox(
                    "Gartic - Login",
                    "User doesn't exist. Please register!",
                    "Register now",
                    [this]() {
                        registerWindow->show();
                        this->close();
                    }
                );
            }
            else if (response_message == "Incorrect password")
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
                showErrorCustomMessageBox(
                    "Gartic - Login",
                    "Something went wrong. Please try again later!",
                    "Ok",
                    []() {
                    }
            );
        }
    }
    else
    {
        showErrorCustomMessageBox(
            "Gartic - Login",
            "Something went wrong. Please try again later!",
            "Ok",
            []() {}
        );
        return;
    }
}