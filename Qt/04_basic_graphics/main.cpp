#include "basic_graphics.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    basic_graphics_MainWindow w;
    w.show();
    return a.exec();
}
