#include "Windows/Frontend/Frontend.h"
#include "Windows/Lobby/Lobby.h"
#include "Widgets/PaintWidget/PaintWidget.h"
#include <QtWidgets/QApplication>
#include "Utils/UserInfo/UserInfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frontend w;
    w.show();
    return a.exec();
}
