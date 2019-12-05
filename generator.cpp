#include "generator.h"
#include<QVector>

generator :: generator (QVector<QChar> newTalph, int newnumber,int newsizeobr,int newsizetext){
Talph=newTalph;
numberobr=newnumber;
sizeobr=newsizeobr;
sizetext=newsizetext;
}
//Генератор образцов
QVector<QVector<QChar>> generator :: get_robr()
    {
         GObraz.resize(numberobr);
         int i=0;
         bool genSuccessful=false;
     while(i<=numberobr-1){
         GObraz[i].resize(sizeobr);
         for(int j=0;j<=sizeobr-1;j++){
             GObraz[i][j]=Talph[rand() % 8];
         }
         for(int rfi=0;rfi<=GObraz.size()-1;rfi++){
            if(GObraz[i]==GObraz[rfi] && i!=rfi){
                genSuccessful=false;
                break;
            }
            if(rfi==GObraz.size()-1) genSuccessful=true;
         }
     if(genSuccessful) i++;
     }
     return GObraz;
     }
//Генератор текста
QVector<QChar> generator::getText()
{
    QVector<QChar> textobr={};
    for(int i=0;i<=sizetext-1;i++)
    {
      textobr.push_back(Talph[rand() % 8]);
    }
    return textobr;
}


