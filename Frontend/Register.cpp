#include "Register.h"
#include "Requests.h"

Register::Register(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Register::~Register()
{}

void Register::on_pushButton_goToLogin_clicked()
{
	emit loginWindow();
	this->close();
}

void Register::on_pushButton_register_clicked()
{
    QString temp_username = ui.lineEdit_username->text();
    QString temp_password = ui.lineEdit_password->text();
    QString temp_surname = ui.lineEdit_surname->text();
    QString temp_given_name = ui.lineEdit_given_name->text();
    std::string username = temp_username.toUtf8().constData();
    std::string password = temp_password.toUtf8().constData();
    std::string surname = temp_surname.toUtf8().constData();
    std::string given_name = temp_given_name.toUtf8().constData();

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
        if (!response_json) {
            showErrorCustomMessageBox(
                "Gartic - Register",
                "Something went wrong. Please try again later!",
                "Ok",
                []() {}
            );
            return;
        }
        else {
            bool success_state = response_json["ResponseState"].b();
            std::string response_message = response_json["ResponseMessage"][0].s();
            int new_user_id = response_json["NewUserID"].i();

            if (response_message == "Success") {
                showSuccessCustomMessageBox(
                    "Gartic - Register",
                    "Register successful. You can login now!",
                    "Log In",
                    [this]() {
                        emit loginWindow();
                        this->close();
                    }
                );
            }
            else if (response_message == "The user already exists") {
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
        }
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
}