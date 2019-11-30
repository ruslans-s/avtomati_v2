#include "generator.h"
#include<QVector>

generator :: generator (QVector<QChar> newTalph, int newnumber,int newsizeobr,int newsizetext){
Talph=newTalph;
numberobr=newnumber;
sizeobr=newsizeobr;
sizetext=newsizetext;
}
QVector<QVector<QChar>> generator :: get_robr()
    {
         GObraz.resize(numberobr);
     for(int i=0;i<=numberobr-1;i++){
         GObraz[i].resize(sizeobr);
         for(int j=0;j<=sizeobr-1;j++){
             GObraz[i][j]=Talph[rand() % 8];
         }
     }
     return GObraz;
     }

QVector<QChar> generator::getText()
{
    QVector<QChar> textobr={};
    for(int i=0;i<=sizetext-1;i++)
    {
      textobr.push_back(Talph[rand() % 8]);
    }
    return textobr;
}


