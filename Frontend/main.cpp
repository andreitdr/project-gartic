#include <QtWidgets/QApplication>
#include "Utils/WindowManager/WindowManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowManager windowManager;
    //windowManager.showLoginWindow();
    windowManager.showGameWindow();
    return a.exec();
}
