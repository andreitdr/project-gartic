#include "Frontend.h"
#include "PaintWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintWidget w;
    w.show();
    return a.exec();
}
