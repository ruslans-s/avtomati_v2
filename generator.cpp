#include "generator.h"
#include<QVector>

generator :: generator (QVector<char> newTalph, int newnumber,int newsizeobr){
Talph=newTalph;
numberobr=newnumber;
sizeobr=newsizeobr;
}
QVector<QVector<char>> generator :: get_robr()
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


