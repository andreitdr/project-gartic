#include "Windows/Frontend/Frontend.h"
#include "Windows/Lobby/Lobby.h"
#include "Widgets/PaintWidget/PaintWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lobby w;
    w.show();
    return a.exec();
}
