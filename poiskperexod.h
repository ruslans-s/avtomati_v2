#ifndef POISKPEREXOD_H
#define POISKPEREXOD_H
#include <QVector>
#include "avtomati.h"
class poiskperexod
{
protected:
    QVector<char> tvec2;
    QVector<char> tvec3;
    QVector<char> tvec4;
    QVector<char> tvec5;
      QVector<char> tvec2t;
    char cr1, cr2;
    QVector<int> Tintvec;
    int max=0;
    int oldmax = 0;
public:
    poiskperexod(QVector<avtomati>&,QVector<char>);
};

#endif // POISKPEREXOD_H
