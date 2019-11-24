#ifndef POISKPUT_H
#define POISKPUT_H
#include <QVector>
#include "avtomati.h"

class poiskput
{
protected:
    QVector <char> Falphab;
    QVector <avtomati> Favtomvec;
    QVector<QVector<char>> Fobraz;
    int r2;
public:
    poiskput(QVector <char>, QVector <avtomati>&, QVector<QVector<char>> ,int);
};

#endif // POISKPUT_H
