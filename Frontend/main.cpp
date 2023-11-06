#include "Frontend.h"
#include "JoinGame.h"
#include "UserProfile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frontend w;
    w.show();
    return a.exec();
}
