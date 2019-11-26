#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generator.h"
#include<QVector>
#include <string>
#include <sstream>
#include <iostream>
#include "avtomati.h"
#include "poiskput.h"
#include "poiskperexod.h"
#include "metod_tabl_per.h"
using namespace std;
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

string tostring(int n)
{
    char buf[40];
    sprintf(buf,"%d",n);
    return buf;
}


void MainWindow::textoutput(QString otxt){
ui->vivod->addItem(otxt);
}


void MainWindow::on_pushButton_clicked()
{
    ui->vivod->clear();
    QVector<avtomati> avtomvec;
    int r1,r2;
   //  r1=4;//Длина образцов
   // r2=3;//Кол-во образцов
    r2=ui->lineEdit->text().toInt();
    r1=ui->lineEdit_2->text().toInt();
   // ui->label->setText("Кнопка Нажата");
    QVector<char> alph = {'s','a','d','i','k','o','v','r'};
    QVector<QVector<char>> Obraz;
    generator generator(alph,r2,r1);
    Obraz = generator.get_robr();
    QString str;
    QString str2;
ui->vivod->addItem("Образцы");
    for (int j=0;j<=r2-1;j++){

    for(int i = 0; i <= r1-1;i++) {
       QString st(QChar(Obraz[j][i]));
        str = str+st;
    }
     ui->vivod->addItem(str);
     str=str2;
    }
    QVector<char> tvec;
    avtomvec.resize(avtomvec.size() + 1);
    tvec={' '};
    avtomvec[0].setPVec(tvec);
    for (int i = 0; i <= r1 - 1; ++i) {
            poiskput(alph, avtomvec, Obraz, i);//Поиск входных данных
     }

/*

    for (int i = 0; i <= avtomvec.size()-1; ++i) {
            tvec = {};
            //cout << 'p' << i <<' ';
            tvec = avtomvec[i].getPPvec();
             str="P"+QString::number(i)+" ";
            for (int j = 0; j <= tvec.size()-1; ++j) {
                QString st(QChar(tvec[j]));
                 str = str+st;

            }
            ui->vivod->addItem(str);
            str=str2;
            //cout << endl;
      }*/
    // Находим финалы
for(int j=0;j<=Obraz.size()-1;j++){
    for (int i=0;i<=avtomvec.size()-1;i++){
        if (Obraz[j]==avtomvec[i].getPPvec()) {
            avtomvec[i].setfinal();
          //   ui->vivod->addItem("Final");
            break;
        }
    }
}
for(int i=0;i<=avtomvec.size()-1;i++){
    if (avtomvec[i].getfinal()==true){
       ui->vivod->addItem(QString::number(i));
       ui->vivod->addItem("Final");
    }

}
//ui->vivod->addItem("'Переходы'");
poiskperexod(avtomvec,alph);
QVector<int> itvec;
str2.clear();
str.clear();
QString st;
/*
for (int i = 0; i <= avtomvec.size()-1; ++i) {
        itvec = {};
        //cout << 'p' << i <<' ';
        itvec = avtomvec[i].getPvec();
           str="P"+QString::number(i)+" ";
        for (int j = 0; j <= itvec.size()-1; ++j) {

            st=QString::number(itvec[j]);
             str = str+st+" ";

        }
        ui->vivod->addItem(str);
        str=str2;
        //cout << endl;
  }*/
QModelIndex index;
model = new QStandardItemModel(avtomvec.size(),9,this);
ui->tabl->setModel(model);
    model->setHeaderData(0,Qt::Horizontal,"P");
    for(int i=1;i<=alph.size();i++){
 model->setHeaderData(i,Qt::Horizontal, QChar(alph[i-1]));
    }
    for(int i=0;i<model->rowCount();i++){
 model->setHeaderData(i,Qt::Vertical, i);
    }
for(int row=0;row<model->rowCount();row++){
     tvec = avtomvec[row].getPPvec();
    for (int j = 0; j <= tvec.size()-1; ++j) {
        QString st(QChar(tvec[j]));
         str = str+st;

    }
    //ui->vivod->addItem(str);

    index=model->index(row,0);
     model->setData(index, str);
    str.clear();

    itvec = {};
    //cout << 'p' << i <<' ';
    itvec = avtomvec[row].getPvec();
       //str="P"+QString::number(i)+" ";
     for(int col=1;col<model->columnCount();col++) {

       // st=;
       index=model->index(row,col);
        model->setData(index, QString::number(itvec[col-1]));
      //  str.clear();

    }



}
QVector<QString> text3;

QVector<char> texto = {'a','i','v','k','a','d','i','s','a','d','v','k'};


metod_tabl_per(alph, avtomvec, Obraz,texto,text3);
ui->vivod->addItem(QString::number(text3.size()));
for(int i=0;i<=text3.size()-1;i++){
ui->vivod->addItem(text3[i]);
}

}
