#include "metod_tabl_per.h"
#include "mainwindow.h"
/*
int metod_tabl_per::getpoisknumber(char simvol,QVector <char> Falphab){
     for (int i=0;i<=Falphab.size()-1;i++){
            if(simvol==Falphab[i]){
                return i;
              //  break;
            }
     }
     return 5;
}*/
/*
void metod_tabl_per::setstr(QString txt){
      vectxt.push_back(txt);
}
QVector<QString>  metod_tabl_per::gettstr(){
      return vectxt;
}*/

metod_tabl_per::metod_tabl_per(QVector <QChar> Falphab, QVector <avtomati> Favtomvec, QVector<QVector<QChar>> Fobraz,QVector <QChar> FText,QVector<QString>& text0, QVector<int>& numberfordel)
{
    QVector<int> tempvec1={};
    QVector<QChar> tempvec2;
    int currentp=0;
    int numbersim=0;
    int s=0;
    QString text1={};
    //for (int i=0;i<=FText.size()-1;i++)
    int i=0;
    int i2=0;
    int k;
    int rf5;
    bool similar;
    while (i<=FText.size()-1){
            //numbersim = getpoisknumber(FText[i],Falphab);
            numbersim=0;
            for (int j=0;j<=Falphab.size()-1;j++){
                   if(FText[i]==Falphab[j]){
                     numbersim= j;
                     break;
              }
            }
            similar=false;
            k=0;
            tempvec2=Favtomvec[currentp].getPPvec();
            tempvec1=Favtomvec[currentp].getPvec();
            if (Favtomvec[currentp].getfinal()==true){
                while(k<=tempvec2.size()-1){
                if(tempvec2[tempvec2.size()-1-k]==FText[i-1-k]) {
                similar=true;
                  k++;
                }else {
                      k++;
                    similar=false;
                    break;
                }

                }
            if(similar){
              s=i-(Fobraz[Favtomvec[currentp].getnumberobr()].size());
              while(s>Favtomvec.size()-1) s=s-Favtomvec.size();
              currentp=s;
              text1.clear();
              text1=QString::number(i-1)+" Вхождение P"+QString::number(Favtomvec[currentp].getnumberobr())+" Со сдвигом "+ QString::number(s);
              text0.resize(text0.size()+1);
              text0[text0.size()-1]=text1;
              rf5=i-1-1;
              for(int rf4=0;rf4<=1;rf4++){
                numberfordel.push_back(rf5);
                rf5++;
              }




            } } else {

                currentp=tempvec1[numbersim];
  }
            i++;
 }
}

