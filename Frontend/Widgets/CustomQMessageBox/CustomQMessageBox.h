#pragma once
#include <qmessagebox.h>
#include <qicon.h>
#include <qpushbutton.h>
#include <functional>
#include <qpixmap.h>

void showSuccessCustomMessageBox(
    const QString& title,
    const QString& message,
    const QString& buttonText,
    std::function<void()> customAction
);

void showErrorCustomMessageBox(
    const QString& title,
    const QString& message,
    const QString& buttonText,
    std::function<void()> customAction
);

void showConfirmActionCustomMessageBox(
    const QString& title,
    const QString& message,
    const QString& yesButtonText,
    const QString& noButtonText,
    std::function<void()> yesAction
);