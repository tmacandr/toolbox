#include "menu_bar_demo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu_bar_demo w;
    w.show();
    return a.exec();
}
