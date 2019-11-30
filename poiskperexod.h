#ifndef POISKPEREXOD_H
#define POISKPEREXOD_H
#include <QVector>
#include "avtomati.h"
class poiskperexod
{
protected:
    QVector<QChar> tvec2;
    QVector<QChar> tvec3;
    QVector<QChar> tvec4;
    QVector<QChar> tvec5;
      QVector<QChar> tvec2t;
    QChar cr1, cr2;
    QVector<int> Tintvec;
    int max=0;
    int oldmax = 0;
public:
    poiskperexod(QVector<avtomati>&,QVector<QChar>);
};

#endif // POISKPEREXOD_H
