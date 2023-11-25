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

void UserProfile::getUser(const UserInfo& user)
{
	m_user = user;
	std::string m_username = m_user.getUsername();
	std::string m_surname = m_user.getSurname();
	std::string m_givenName = m_user.getGivenName();
	QString username = QString::fromUtf8(m_username.c_str());
	QString surname = QString::fromUtf8(m_surname.c_str());
	QString givenName = QString::fromUtf8(m_givenName.c_str());

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
		QString temp = "@" + username;
		usernameLabel->setText(temp);
	}
}