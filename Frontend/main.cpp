#include "Frontend.h"
#include "JoinGame.h"
#include "LobbyPlayerInfoWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LobbyPlayerInfoWidget w("alehh69","Pestritu","Alexandru",true);
    w.show();
    return a.exec();
}
