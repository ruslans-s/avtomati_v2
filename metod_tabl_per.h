#ifndef METOD_TABL_PER_H
#define METOD_TABL_PER_H
//#include "mainwindow.h"
#include <QVector>
#include "avtomati.h"
class metod_tabl_per
{
protected:
   // QVector<QString> vectxt;
    QVector <char> Falphab;
    QVector <avtomati> Favtomvec;
    QVector<QVector<char>> Fobraz;
    QVector<QString> text0;
public:
    metod_tabl_per(QVector <char>, QVector <avtomati>, QVector<QVector<char>>,QVector <char>,QVector<QString>&, QVector<int>& );
//    int getpoisknumber(char,QVector <char>);
//    void setstr(QString);
 //   QVector<QString> gettstr();
};

#endif // METOD_TABL_PER_H
