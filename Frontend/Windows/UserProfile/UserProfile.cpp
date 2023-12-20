#include "UserProfile.h"
#include "../../Utils/CurrentUser/CurrentUser.h"
#include "../../API/Contexts/Contexts.h"

UserProfile::UserProfile(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

UserProfile::~UserProfile()
{}

void UserProfile::showEvent(QShowEvent* event)
{
	QWidget::showEvent(event);
	updateUserInfoDisplay();
}

void UserProfile::updateUserInfoDisplay()
{
	CurrentUser& user = CurrentUser::getInstance();
	QString username = QString::fromUtf8(user.getUsername().c_str());
	QString surname = QString::fromUtf8(user.getSurname().c_str());
	QString givenName = QString::fromUtf8(user.getGivenName().c_str());

	ui.label_user_profile_letter->setText(givenName[0]);
	ui.label_user_profile_letter->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

	QString temp_name = givenName + " " + surname;
	ui.label_name->setText(temp_name);

	QString temp_username = "@" + username;
	ui.label_username->setText(temp_username);
}

void UserProfile::on_pushButton_goBackUserProfile_clicked()
{
	emit goToJoinGameWindow();
	this->close();
}