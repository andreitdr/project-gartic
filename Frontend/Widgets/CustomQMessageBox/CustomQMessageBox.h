#pragma once
#include <qmessagebox.h>
#include <qicon.h>
#include <qpushbutton.h>
#include <functional>
#include <qpixmap.h>

void showSuccessCustomMessageBox(
    QWidget* parent,
    const QString& title,
    const QString& message,
    const QString& buttonText,
    std::function<void()> customAction
);

void showErrorCustomMessageBox(
    QWidget* parent,
    const QString& title,
    const QString& message,
    const QString& buttonText,
    std::function<void()> customAction
);

void showConfirmActionCustomMessageBox(
    QWidget* parent,
    const QString& title,
    const QString& message,
    const QString& yesButtonText,
    const QString& noButtonText,
    std::function<void()> yesAction
);