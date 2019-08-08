#include "mainwindow.h"
#include "protectormain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    protectormain w;
    //MainWindow w;
    w.show();
    return a.exec();
}
