#include "Register.h"
#include "../../API/Requests/Requests.h"
#include "../../API/ResponseHandler/ResponseHandler.h"

Register::Register(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Register::~Register()
{}

void Register::on_pushButton_goToLogin_clicked()
{
	emit goToLogin();
    this->hide();
}

void Register::on_pushButton_register_clicked() {
    std::string username = ui.lineEdit_username->text().toUtf8().constData();
    std::string password = ui.lineEdit_password->text().toUtf8().constData();
    std::string surname = ui.lineEdit_surname->text().toUtf8().constData();
    std::string given_name = ui.lineEdit_given_name->text().toUtf8().constData();

    if (username.empty() || password.empty() || surname.empty() || given_name.empty()) {
        showErrorCustomMessageBox(
            "Gartic - Register",
            "One or more fields is empty. Please try again!",
            "Try Again",
            []() {}
        );
        return;
    }

    if (password.length() < 8) {
        showErrorCustomMessageBox(
            "Gartic - Register",
            "Password should be at least 8 characters. Please try again!",
            "Try Again",
            []() {}
        );
        return;
    }

    auto response = Requests::RegisterUser(surname, given_name, username, password);
    if (response.status_code == 200) {
        auto response_json = crow::json::load(response.text);

        ResponseHandler handler;
        handler.processRegisterResponse(response_json, [this](bool success, const std::string& message, int new_user_id) {
            if (success) {
                showSuccessCustomMessageBox(
                    "Gartic - Register",
                    "Register successful. You can login now!",
                    "Log In",
                    [this]() {
                        emit goToLogin();
                        this->hide();
                    }
                );
            }
            else if (message == "The user already exists") {
                showErrorCustomMessageBox(
                    "Gartic - Register",
                    "Username already exists. Please try again!",
                    "Try Again",
                    []() {}
                );
                return;
            }
            else {
                showErrorCustomMessageBox(
                    "Gartic - Register",
                    "Something went wrong. Please try again later!",
                    "Ok",
                    []() {}
                );
                return;
            }
            });
    }
    else {
        showErrorCustomMessageBox(
            "Gartic - Register",
            "Something went wrong. Please try again later!",
            "Ok",
            []() {}
        );
    }
}