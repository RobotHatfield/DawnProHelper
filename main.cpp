#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Pro Feed Gen");
    a.setOrganizationName("Dawn");
    MainWindow w;
    w.show();
    
    return a.exec();
}
