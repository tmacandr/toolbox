#include "data_entry.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    data_entry w;
    w.show();
    return a.exec();
}
