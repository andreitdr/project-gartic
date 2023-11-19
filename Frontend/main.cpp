#include "Frontend.h"
#include "PaintWidget.h"
#include "DisplayPaintWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frontend w;
    w.show();
    return a.exec();
}
