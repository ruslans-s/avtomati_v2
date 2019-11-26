#include "metod_tabl_per.h"
#include "mainwindow.h"

int metod_tabl_per::getpoisknumber(char simvol,QVector <char> Falphab){
     for (int i=0;i<=Falphab.size()-1;i++){
            if(simvol==Falphab[i]){
                return i;
              //  break;
            }
     }
     return 5;
}
/*
void metod_tabl_per::setstr(QString txt){
      vectxt.push_back(txt);
}
QVector<QString>  metod_tabl_per::gettstr(){
      return vectxt;
}*/

metod_tabl_per::metod_tabl_per(QVector <char> Falphab, QVector <avtomati>& Favtomvec, QVector<QVector<char>> Fobraz,QVector <char> FText,QVector<QString>& text0)
{
    QVector<int> tempvec1;
    int currentp=0;
    int numbersim;
    int s;
    QString text1;
    //for (int i=0;i<=FText.size()-1;i++)
    int i=0;
    while (i<=FText.size()-1){
            //numbersim = getpoisknumber(FText[i],Falphab);
            numbersim=0;
            for (int j=0;j<=Falphab.size()-1;j++){
                   if(FText[i]==Falphab[j]){
                       numbersim= j;
                       break;
                   }
            }
            tempvec1=Favtomvec[currentp].getPvec();
            if (Favtomvec[currentp].getfinal()==true){


              s=i-(Fobraz[Favtomvec[i].getnumberobr()].size());
              currentp=s;
                text1.clear();
                text1=QString::number(i-1)+" Вхождение P"+QString::number(Favtomvec[currentp].getnumberobr())+" Со сдвигом "+ QString::number(s);
               text0.resize(text0.size()+1);
               text0[text0.size()-1]=text1;
            } else {
             i++;
                currentp=tempvec1[numbersim];
            }
        }
}

