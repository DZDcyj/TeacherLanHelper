#include "mainwindow.h"
#include "protectormain.h"
#include "saving.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    protectormain w;
    w.show();
    return a.exec();
}
