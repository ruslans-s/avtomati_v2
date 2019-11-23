#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generator.h"
#include<QVector>
#include <string>
#include <sstream>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{

    ui->label->setText("Кнопка Нажата");
    QVector<char> alph = {'s','a','d','i','k','o','v','r'};
    QVector<QVector<char>> Obraz;
    generator generator(alph,3,4);
    Obraz = generator.get_robr();
    for(int i = 0; i <= 2;i++) {
        //QString str;
       QString st(QChar(Obraz[0][i]));
        //str = st;
        ui->vivod->addItem(st);
    }
}
