//----------------------------------------------------------------------------
// FILE: hello_world.cpp
//
// DESCRIPTION:
//    Direct copy of the 'hello world' from google of a Qt hello world.
//
//    Not sure if I violate some copyright, but this is my first attempt
//    at writing Qt GUIs.  So how many ways can a Qt hello world be
//    written?
//
//    Anyway, so X/Xt/Xm days are long gone.  Apparently, if one is going
//    to do GUIs on Linux or Windows (10 or 11), then Qt is what people
//    are using.
//
//    At first glance, looks rather bare-bones, which means the Qt functions
//    are hiding a lot.
//----------------------------------------------------------------------------
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");

    hello.show();

    return app.exec();
}

// EOF

