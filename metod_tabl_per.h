#ifndef METOD_TABL_PER_H
#define METOD_TABL_PER_H
//#include "mainwindow.h"
#include <QVector>
#include "avtomati.h"
class metod_tabl_per
{
protected:
   // QVector<QString> vectxt;
    QVector <QChar> Falphab;
    QVector <avtomati> Favtomvec;
    QVector<QVector<QChar>> Fobraz;
    QVector<QString> text0;
public:
    metod_tabl_per(QVector <QChar>, QVector <avtomati>, QVector<QVector<QChar>>,QVector <QChar>,QVector<QString>&, QVector<int>& );
//    int getpoisknumber(char,QVector <char>);
//    void setstr(QString);
 //   QVector<QString> gettstr();
};

#endif // METOD_TABL_PER_H
