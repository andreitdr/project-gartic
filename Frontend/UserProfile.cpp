#include "UserProfile.h"

UserProfile::UserProfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QLabel* avatarLetter = findChild<QLabel*>("label_user_profile_letter");

	if (avatarLetter) {
		//to be linked with backend or passed from previous windows
		avatarLetter->setText("P");
		avatarLetter->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
	}

	QLabel* name = findChild<QLabel*>("label_name");

	if (name) {
		//to be linked with backend or passed from previous windows
		name->setText("Alexandru Pestritu");
	}

	QLabel* username = findChild<QLabel*>("label_username");

	if (username) {
		//to be linked with backend or passed from previous windows
		username->setText("@alehh69");
	}
}

UserProfile::~UserProfile()
{}
