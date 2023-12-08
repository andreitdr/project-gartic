#pragma once

#include <QWidget>
#include "ui_LobbyPlayerInfoWidget.h"

class LobbyPlayerInfoWidget : public QWidget
{
    Q_OBJECT

public:
    LobbyPlayerInfoWidget(QWidget* parent = nullptr);
    LobbyPlayerInfoWidget(const QString& username, const QString& surname, const QString& givenName, bool isAdmin, QWidget* parent = nullptr); // Adăugat parent aici
    ~LobbyPlayerInfoWidget();
    QString getUsername() const;

private:
    Ui::LobbyPlayerInfoWidgetClass ui;
};