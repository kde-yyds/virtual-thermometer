#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setStyleSheet("background:rgba(255,255,255,10);"); //to enable background blur (kwin) , you should install kwin script "force blur"
    return a.exec();
}
