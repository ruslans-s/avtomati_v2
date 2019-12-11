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
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
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
 bool found=false;
 temptext=ui->lineEdit_5->text();
 for(int i=0;i<=temptext.size()-1;i++){

      if (std::find(std::begin(alph), std::end(alph), temptext[i]) != std::end(alph)){
    // if(found==true){
     tempvecchar.resize(tempvecchar.size()+1);
     tempvecchar[tempvecchar.size()-1]=(temptext[i]);
     }else{
(new QErrorMessage(this))->showMessage("В образце есть недопустимые символы");
         return ;
 }
    //tempvecchar.push_back(temptext[i]);
 }
 Obraz.push_back(tempvecchar);
 ui->lineEdit_5->clear();
 QString tempString;
 for(int i=0;i<=tempvecchar.size()-1;i++){
    tempString+=tempvecchar[i];
 }
 ui->vivod->addItem(tempString);
}


void MainWindow::vivod(QString text){
ui->vivod->addItem(text);
}

void MainWindow::on_pushButton_clicked()
{

    ui->vivod->clear();
    //ui->text_conclusion->clear();
    QVector<avtomati> avtomvec;
    avtomvec.clear();

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
     ui->vivod->addItem('P'+QString::number(j)+'='+str);
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

QVector<QString> text3={};
QVector<int> numberfodel;

metod_tabl_per(alph, avtomvec, Obraz,texto,text3,numberfodel);//Применение текста к автомату



model = new QStandardItemModel(1,texto.size(),this);
ui->textOutput->setModel(model);
    for(int i=0;i<=texto.size();i++){
 model->setHeaderData(i,Qt::Horizontal, QString::number(i+1));
    }
 model->setHeaderData(0,Qt::Vertical, "Исходный текст");
   str.clear();
     for(int col=0;col<model->columnCount();col++) {
       index=model->index(0,col);
        model->setData(index, texto[col]);
    }
str.clear();


for(int i=0;i<=text3.size()-1;i++){
ui->vivod->addItem(text3[i]);
}

//Вывод подстрок не совпадаюших ни с одним образцом
ui->vivod->addItem("Подстроки, не совпадающие ни с одним из образцов:");
str.clear();
int pos=0;
int rfi8=0;

//    if(rfi8!=texto.size() && rfi8!=texto.size()-1){
//        if(pos>numberfodel.size()) {pos=numberfodel.size()-1;}
//    if(numberfodel[pos]!=rfi8 ){
//   str+=texto[rfi8];
//    rfi8++;
//    }else{
//        ui->vivod->addItem(str);
//        str.clear();
//        rfi8+=r1;
//        pos++;
//    }
//    if(pos>numberfodel.size()-1) pos=numberfodel.size()-1;

//}

QVector<QString> tempVecStr;
tempVecStr.resize(1);
if(numberfodel.count()>0){
while (rfi8<texto.size()) {
     if(pos>numberfodel.size()-1 && numberfodel.count()==0) {
         pos=0;
        }else if(pos>numberfodel.size()-1) pos=numberfodel.size()-1;


    if(rfi8==numberfodel[pos]){
        tempVecStr.resize(tempVecStr.size()+1);
        pos++;
        rfi8++;
    } else{
        tempVecStr[tempVecStr.size()-1]=tempVecStr[tempVecStr.size()-1]+texto[rfi8];
        rfi8++;
    }
}
for(int i=0;i<=tempVecStr.size()-1;i++){
    if(tempVecStr[i].count() != 0 ) ui->vivod->addItem(tempVecStr[i]);
}
} else {
    str.clear();
    for(int i=0;i<=texto.size()-1;i++){
        str+=texto[i];
    }
    ui->vivod->addItem(str);
}

}



void MainWindow::on_pushButton_3_clicked()
{
    QString fileName=QFileDialog::getSaveFileName( 0,"Сохранить файл как","C:\\Users\\User\\Desktop","txt(*.txt)" );
    QFile file(fileName);

    QTextCodec *codec = QTextCodec::codecForName("UTF8");
  //  QTextCodec::setCodecForTr(codec);
  //  QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextStream out(&file);


    out.setCodec("UTF-8");
    out.flush();
    if (file.open(QIODevice::WriteOnly))
    {
       // out<<"Заданные параметры:" << endl;
    //    out<<"Количество образцов: "<< QString::number(r2) << endl;
     //   out<<"Длина образцов: "<< QString::number(r1) << endl;
      //  out<<"Длина текста: "<< QString::number(r3) << endl;
        for(int i=0;i<ui->vivod->count();i++){
            out<<ui->vivod->item(i)->text() << endl;
        }

        file.close();
    }
}
