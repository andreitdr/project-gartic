#include "CustomQMessageBox.h"

void showSuccessCustomMessageBox(
    const QString& title,
    const QString& message,
    const QString& buttonText,
    std::function<void()> customAction
) {
    QMessageBox customMessageBox;
    customMessageBox.setWindowTitle(title);
    customMessageBox.setText(message);
    customMessageBox.setWindowIcon(QIcon(":/Frontend/assets/images/appicon.ico"));
    QPushButton* customButton = customMessageBox.addButton(buttonText, QMessageBox::ActionRole);
    QPixmap pixmap(":/Frontend/assets/images/accept.ico");
    pixmap = pixmap.scaledToWidth(30, Qt::SmoothTransformation);
    customMessageBox.setIconPixmap(pixmap);

    customMessageBox.setStyleSheet(
        "QMessageBox { background-color: #ffffff; }"
        "QMessageBox QLabel#qt_msgbox_label { padding-top: 5px; }"
        "QMessageBox QPushButton { color: #000000; background-color: #ffbf00; border-radius: 5px; padding: 7px; }"
        "QMessageBox QPushButton:hover, QPushButton:pressed { background-color: rgb(225, 165, 0);}"
        "QDialogButtonBox { qproperty-centerButtons: true; }"
    );

    customMessageBox.exec();

    if (customMessageBox.clickedButton() == customButton) {
        customAction();
    }
}


void showErrorCustomMessageBox(
    const QString& title,
    const QString& message,
    const QString& buttonText,
    std::function<void()> customAction
) {
    QMessageBox customMessageBox;
    customMessageBox.setWindowTitle(title);
    customMessageBox.setText(message);
    customMessageBox.setWindowIcon(QIcon(":/Frontend/assets/images/appicon.ico"));
    QPushButton* customButton = customMessageBox.addButton(buttonText, QMessageBox::ActionRole);
    QPixmap pixmap(":/Frontend/assets/images/cancel.ico");
    pixmap = pixmap.scaledToWidth(30, Qt::SmoothTransformation);
    customMessageBox.setIconPixmap(pixmap);

    customMessageBox.setStyleSheet(
        "QMessageBox { background-color: #ffffff; }"
        "QMessageBox QLabel#qt_msgbox_label { padding-top: 5px; }"
        "QMessageBox QPushButton { color: #000000; background-color: #ffbf00; border-radius: 5px; padding: 7px; }"
        "QMessageBox QPushButton:hover, QPushButton:pressed { background-color: rgb(225, 165, 0);}"
        "QDialogButtonBox { qproperty-centerButtons: true; }"
    );

    customMessageBox.exec();

    if (customMessageBox.clickedButton() == customButton) {
        customAction();
    }
}

void showConfirmActionCustomMessageBox(const QString& title, const QString& message, const QString& yesButtonText, const QString& noButtonText, std::function<void()> yesAction)
{
    QMessageBox customMessageBox;
    customMessageBox.setWindowTitle(title);
    customMessageBox.setText(message);
    customMessageBox.setWindowIcon(QIcon(":/Frontend/assets/images/appicon.ico"));

    QPushButton* yesButton = customMessageBox.addButton(yesButtonText, QMessageBox::ActionRole);
    QPushButton* noButton = customMessageBox.addButton(noButtonText, QMessageBox::RejectRole);
    QPixmap pixmap(":/Frontend/assets/images/cancel.ico");
    pixmap = pixmap.scaledToWidth(30, Qt::SmoothTransformation);
    customMessageBox.setIconPixmap(pixmap);

    customMessageBox.setStyleSheet(
        "QMessageBox { background-color: #ffffff; }"
        "QMessageBox QLabel#qt_msgbox_label { padding-top: 5px; }"
        "QMessageBox QPushButton { color: #000000; background-color: #ffbf00; border-radius: 5px; padding: 7px; }"
        "QMessageBox QPushButton:hover, QPushButton:pressed { background-color: rgb(225, 165, 0);}"
        "QDialogButtonBox { qproperty-centerButtons: true; }"
    );

    customMessageBox.exec();

    if (customMessageBox.clickedButton() == yesButton) {
        yesAction();
    }
}
