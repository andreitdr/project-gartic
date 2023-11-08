#include "UserProfile.h"

UserProfile::UserProfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

UserProfile::~UserProfile()
{}

void UserProfile::on_pushButton_goBackUserProfile_clicked()
{
	this->close();
	emit joinGameWindow();
}

void UserProfile::getUsername(const QString& username)
{
	m_username = username;
	QString surname = "FirstName"; //to be optained from database by username
	QString givenName = "SecondName"; //to be optained from database by username

	QLabel* avatarLetter = findChild<QLabel*>("label_user_profile_letter");
	if (avatarLetter) {
		avatarLetter->setText(givenName[0]);
		avatarLetter->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
	}

	QLabel* nameLabel = findChild<QLabel*>("label_name");
	if (nameLabel) {
		QString temp = givenName + " " + surname;
		nameLabel->setText(temp);
	}

	QLabel* usernameLabel = findChild<QLabel*>("label_username");
	if (usernameLabel) {
		QString temp = "@" + m_username;
		usernameLabel->setText(temp);
	}
}