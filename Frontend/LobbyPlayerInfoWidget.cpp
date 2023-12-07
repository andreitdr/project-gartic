#include "LobbyPlayerInfoWidget.h"

LobbyPlayerInfoWidget::LobbyPlayerInfoWidget(QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);
}

LobbyPlayerInfoWidget::LobbyPlayerInfoWidget(const QString& username, const QString& surname, const QString& givenName, bool isAdmin, QWidget* parent)
    : QWidget(parent) 
{
    ui.setupUi(this);
    QString tempUsername = "@" + username;
    ui.label_username->setText(tempUsername);
    QString tempName = givenName + " " + surname;
    ui.label_surnameGivenName->setText(tempName);
    QString avatarLetter = givenName[0];
    ui.label_avatarLetter->setText(avatarLetter);
    if (isAdmin)
        ui.label_isAdmin->show();
    else
        ui.label_isAdmin->hide();
}

LobbyPlayerInfoWidget::~LobbyPlayerInfoWidget()
{}

QString LobbyPlayerInfoWidget::getUsername() const
{
    return ui.label_username->text();
}
