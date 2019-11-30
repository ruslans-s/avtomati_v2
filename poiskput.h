#ifndef POISKPUT_H
#define POISKPUT_H
#include <QVector>
#include "avtomati.h"

class poiskput
{
protected:
    QVector <QChar> Falphab;
    QVector <avtomati> Favtomvec;
    QVector<QVector<QChar>> Fobraz;
    int r2;
public:
    poiskput(QVector <QChar>, QVector <avtomati>&, QVector<QVector<QChar>> ,int);
};

#endif // POISKPUT_H
