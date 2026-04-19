//============================================================================
// FILE: main.cpp
//
// DESCRIPTION:
//    Main entry point of Qt app to demo basics graphics operations.
//============================================================================
#include "basic_graphics.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    basic_graphics_MainWindow w;
    w.show();
    return a.exec();
}

/* EOF */

