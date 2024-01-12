#include "Windows/Login/Login.h"
#include "Windows/Lobby/Lobby.h"
#include "Widgets/PaintWidget/PaintWidget.h"
#include <QtWidgets/QApplication>
#include "Utils/WindowManager/WindowManager.h"
#include "Utils/UserInfo/UserInfo.h"
#include "Windows/GameWindow/GameWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowManager windowManager;
    //windowManager.showLoginWindow();
    windowManager.showGameWindow();
    return a.exec();
}
