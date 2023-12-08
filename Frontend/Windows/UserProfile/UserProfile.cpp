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
	emit joinGameWindow();
	this->close();
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

	ui.label_user_profile_letter->setText(givenName[0]);
	ui.label_user_profile_letter->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

	QString temp_name = givenName + " " + surname;
	ui.label_name->setText(temp_name);

	QString temp_username = "@" + username;
	ui.label_username->setText(temp_username);
}