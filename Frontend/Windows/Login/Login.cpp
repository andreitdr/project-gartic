#include "Login.h"

Login::Login(QWidget *parent)
	: QMainWindow(parent)
{
    ui.setupUi(this);
    registerWindow = new Register();
    connect(registerWindow, &Register::loginWindow, this, &Login::show);
    joinGameWindow = new JoinGame();
    connect(joinGameWindow, &JoinGame::loginWindow, this, &Login::show);
    connect(this, SIGNAL(sendUser(const UserInfo&)), joinGameWindow, SLOT(getUser(const UserInfo&)));
}

Login::~Login()
{}

void Login::on_pushButton_goToRegister_clicked()
{
    registerWindow->show();
    this->close();
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

    auto response = Requests::LoginUser(username, password);
    if (response.status_code == 200)
    {
        auto response_json = crow::json::load(response.text);

        ResponseHandler handler;
        handler.processLoginResponse(response_json, [this](bool success, const std::string& message, const UserInfo& userInfo)
            {
                if (success)
                {
                    m_user = userInfo;
                    emit sendUser(m_user);
                    showSuccessCustomMessageBox(
                        "Gartic - Login",
                        "Successful login. You can play now!",
                        "Play Now",
                        [this]() {
                            joinGameWindow->show();
                            this->close();
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
                            registerWindow->show();
                            this->close();
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
    else
    {
        showErrorCustomMessageBox(
            "Gartic - Login",
            "Something went wrong. Please try again later!",
            "Ok",
            []() {}
        );
    }
}