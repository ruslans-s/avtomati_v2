#include "mainwindow.h"
#include<QLabel>
#include <QApplication>
#include "generator.h"
using namespace std;


int main(int argc, char *argv[])
{
   // generator generator;

    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}

