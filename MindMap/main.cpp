#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QStyleFactory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.setStyleSheet("background-color: #222831");
    w.showMaximized();
    return a.exec();
}
