#include "pop_up_demo_main_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pop_up_demo_Main_Window w;
    w.show();
    return a.exec();
}
