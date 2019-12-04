#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generator.h"
#include<QVector>
#include <QString>
#include <sstream>
#include <iostream>
#include "avtomati.h"
#include "poiskput.h"
#include "poiskperexod.h"
#include "metod_tabl_per.h"
#include <QFile>
#include "nastorika_text.h"
#include <algorithm>
#include <QChar>
#include <QErrorMessage>
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

//Ручной ввод образцов
void MainWindow::on_pushButton_2_clicked()
{
 QString temptext;
 QVector<QChar> tempvecchar;
 temptext=ui->lineEdit_5->text();
 for(int i=0;i<=temptext.size()-1;i++){
     if (std::find(std::begin(alph), std::end(alph), temptext[i]) != std::end(alph)){
       tempvecchar.push_back(temptext[i]);
     }else{
(new QErrorMessage(this))->showMessage("В образце есть недопустимые символы");
         return ;
 }
    tempvecchar.push_back(temptext[i]);
 }
 Obraz.push_back(tempvecchar);
 ui->lineEdit_5->clear();
}


void MainWindow::vivod(QString text){
ui->vivod->addItem(text);
}

void MainWindow::on_pushButton_clicked()
{

    ui->vivod->clear();
    ui->text_conclusion->clear();
    QVector<avtomati> avtomvec;
    avtomvec.clear();
    int r1,r2,r3;
    //Инициализация параметров
    r2=ui->lineEdit->text().toInt();
    r1=ui->lineEdit_2->text().toInt();
    r3=ui->lineEdit_3->text().toInt();
    QVector<QChar> texto ;
      QVector<QChar> texForSave ;
    generator generator(alph,r2,r1,r3);

 if (ui->randomtext->isChecked()){
     //Генерация текста
    texto=generator.getText();
 }
    //Ручной ввод текста
 if (ui->enteText->isChecked()){
   QString tempText=ui->lineEdit_4->text().toLocal8Bit();
   for (int i=0;i<=tempText.size()-1;i++){
       if (std::find(std::begin(alph), std::end(alph), tempText[i]) != std::end(alph)){
            texto.push_back(tempText[i]);
       }else{
            (new QErrorMessage(this))->showMessage("В тексте есть недопустимые символы");
            return ;
   }
 }}
 texForSave=texto;
if(ui->radioButton->isChecked()) texto=texForSave;
    //Создание случайных образцов с заданныит параметрами
 if(ui->randomSample->isChecked()==true){
   Obraz = generator.get_robr();
}


    QString str={};
    QString str2={};
    //Вывод образцов
    ui->vivod->addItem("Образцы");
    for (int j=0;j<=r2-1;j++){
    for(int i = 0; i <= r1-1;i++) {
        str = str+Obraz[j][i];
    }
     ui->vivod->addItem(str);
     str=str2;
    }
    QVector<QChar> tvec={};
    avtomvec.resize(avtomvec.size() + 1);
    tvec={' '};
    avtomvec[0].setPVec(tvec);
    for (int i = 0; i <= r1 - 1; ++i) {
            poiskput(alph, avtomvec, Obraz, i);//Поиск входных данных
     }

    // Нахохождение всех финальны состояний
for(int j=0;j<=Obraz.size()-1;j++){
    for (int i=0;i<=avtomvec.size()-1;i++){
        if (Obraz[j]==avtomvec[i].getPPvec()) {
            avtomvec[i].setfinal();
          //   ui->vivod->addItem("Final");
            break;
        }
    }
}

// Запись номеров образцов в состояния
for(int j=0;j<=Obraz.size()-1;j++){
    if(avtomvec[j].getfinal()==true){
for (int i=0; i<=Obraz.size()-1;++i){
       if(avtomvec[j].getPPvec()==Obraz[i]){
avtomvec[i].setnumberobr(i);
break;
       }
}
    }
}


poiskperexod(avtomvec,alph);//Поиск переходов
QVector<int> itvec={};
str2.clear();
str.clear();
QString st={};

//Вывод таблицы переходов
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

         str = str+tvec[j];

    }
    index=model->index(row,0);
     model->setData(index, str);
    str.clear();

    itvec = {};

    itvec = avtomvec[row].getPvec();

     for(int col=1;col<model->columnCount();col++) {


       index=model->index(row,col);
        model->setData(index, QString::number(itvec[col-1]));


    }



}
str.clear();

        for (int j = 0; j <= texto.size()-1; ++j) {
            st=QChar(texto[j]);
             str =str+ QString::number(j)+st+" ";
        }
        ui->text_conclusion->addItem(str);


QVector<QString> text3={};
QVector<int> numberfodel;

metod_tabl_per(alph, avtomvec, Obraz,texto,text3,numberfodel);//Применение текста к автомату

for(int i=0;i<=text3.size()-1;i++){
ui->vivod->addItem(text3[i]);
}
int pos;
for(int i=0;i<numberfodel.size()-1;i++){
    pos=numberfodel[i]-i;
texto.erase(texto.begin()+pos);
}
str.clear();
for (int j = 0; j <= texto.size()-1; ++j) {
    st=QChar(texto[j]);
     str =str+ QString::number(j)+st+" ";
}
ui->text_conclusion->addItem(str);
}



