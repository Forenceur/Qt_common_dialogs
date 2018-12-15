#include <iostream>
#include <QApplication>
#include "mywin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    MyWin windows;
    windows.show();

    return app.exec();
}
