#include "Register.h"


Register::Register(QWidget *parent)
	: QMainWindow(parent)
{
	setAttribute(Qt::WA_DeleteOnClose, true);
	ui.setupUi(this);
}

Register::~Register()
{}

void Register::on_pushButton_goToLogin_clicked()
{
	this->close();
	emit loginWindow();
}

void Register::on_pushButton_register_clicked()
{
	QString username = ui.lineEdit_username->text();
	QString password = ui.lineEdit_password->text();
	QString surname = ui.lineEdit_surname->text();
	QString given_name = ui.lineEdit_given_name->text();

    if (username == "\0" || password == "\0" || surname=="\0"||given_name=="\0")
        showErrorCustomMessageBox(
            "Gartic - Register",
            "One or more fields is empty. Please try again!",
            "Try Again",
            []() {
            }
    );
    else
        //user already exists - to be linked with backend
        if (username == "1" || password == "1" || surname == "1" || given_name == "1")
            showErrorCustomMessageBox(
                "Gartic - Register",
                "Username already registered. Please login!",
                "Log In",
                [this]() {
                    this->close();
                    emit loginWindow();
                }
    );
        else
            if (password.length()<8)
                showErrorCustomMessageBox(
                    "Gartic - Register",
                    "Password should be at least 8 characters. Please try again!",
                    "Try Again",
                    []() {
                    }
    );
            else
                //register successful - to be linked with backend
                if (username == "2" || password == "12345678" || surname == "2" || given_name == "2")
                    showSuccessCustomMessageBox(
                        "Gartic - Register",
                        "Register successful. You can login now!",
                        "Log In",
                        [this]() {
                            this->close();
                            emit loginWindow();
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