#include "Register.h"
#include <regex>

Register::Register(Contexts* contexts,QWidget *parent)
	: QMainWindow(parent),
    contexts(contexts)
{
	ui.setupUi(this);
}

Register::~Register()
{}

bool Register::validateName(const std::string & name)
{
    std::regex nameRegex("^[A-Z][a-z]+$");
    return std::regex_match(name, nameRegex);
}

bool Register::validateUsername(const std::string& username)
{
    std::regex usernameRegex("^[a-zA-Z0-9_]{5,20}$");
    return std::regex_match(username, usernameRegex);
}

bool Register::validatePassword(const std::string& password)
{
    std::regex passwowrdRegex("^(?=.*[A-Z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    return std::regex_match(password, passwowrdRegex);
}

void Register::on_pushButton_goToLogin_clicked()
{
    emit windowPositionChanged(this->pos());
	emit goToLogin();
    this->hide();
}

void Register::on_pushButton_register_clicked() 
{
    std::string username = ui.lineEdit_username->text().toUtf8().constData();
    std::string password = ui.lineEdit_password->text().toUtf8().constData();
    std::string surname = ui.lineEdit_surname->text().toUtf8().constData();
    std::string given_name = ui.lineEdit_given_name->text().toUtf8().constData();

    if (username.empty() || password.empty() || surname.empty() || given_name.empty()) {
        showErrorCustomMessageBox(
            this,
            "Gartic - Register",
            "One or more fields is empty. Please try again!",
            "Try Again",
            []() {}
        );
        return;
    }

    if (!validateName(surname)) {
        showErrorCustomMessageBox(
            this,
            "Gartic - Register",
            "Surname should:\n • Start with a capital letter\n • Contain only letters",
            "Try Again",
            []() {}
        );
        return;
    }

    if (!validateName(given_name)) {
        showErrorCustomMessageBox(
			this,
			"Gartic - Register",
			"Given name should:\n • Start with a capital letter\n • Contain only letters",
			"Try Again",
			[]() {}
		);
		return;
	}

    if (!validateUsername(username)) {
        showErrorCustomMessageBox(
			this,
			"Gartic - Register",
			"Username should:\n • Contain only letters, digits and underscores\n • Be between 5 and 20 characters long",
			"Try Again",
			[]() {}
		);
		return;
	}

    if (!validatePassword(password)) {
        showErrorCustomMessageBox(
            this,
            "Gartic - Register",
            "Password should:\n • Be at least 8 charachers long\n • Contain both letters and numbers\n • Contain one capital letter",
            "Try Again",
            []() {}
        );
        return;
    }

    contexts->registerUser(surname, given_name, username, password, [this](bool success, const std::string& message)
        {
            if (success) {
                showSuccessCustomMessageBox(
                    this,
                    "Gartic - Register",
                    "Register successful. You can login now!",
                    "Log In",
                    [this]() {
                        emit windowPositionChanged(this->pos());
                        emit goToLogin();
                        this->hide();
                    }
                );
            }
            else if (message == "The user already exists") {
                showErrorCustomMessageBox(
                    this,
                    "Gartic - Register",
                    "Username already exists. Please try again!",
                    "Try Again",
                    []() {}
                );
                return;
            }
            else {
                showErrorCustomMessageBox(
                    this,
                    "Gartic - Register",
                    "Something went wrong. Please try again later!",
                    "Ok",
                    []() {}
                );
                return;
            }
        });
}