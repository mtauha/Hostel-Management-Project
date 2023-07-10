#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    w.setWindowTitle("Hostel Management System");
    w.show();
    return a.exec();
}
