#pragma once

#include <QWidget>
#include "ui_LobbyPlayerInfoWidget.h"

class LobbyPlayerInfoWidget : public QWidget
{
    Q_OBJECT

public:
    LobbyPlayerInfoWidget(QWidget* parent = nullptr);
    LobbyPlayerInfoWidget(const QString& username, const QString& surname, const QString& givenName, QWidget* parent = nullptr); 
    ~LobbyPlayerInfoWidget();
    QString getUsername() const;
    bool getAdminStatus() const;
    void updateAdminStatus(bool isAdmin);

private:
    Ui::LobbyPlayerInfoWidgetClass ui;
};