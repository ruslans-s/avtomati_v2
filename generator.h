#ifndef GENERATOR_H
#define GENERATOR_H
#include <QVector>

class generator
{
protected:
    QVector<QVector<char>> GObraz;
    QVector<char> Talph;
    int numberobr;
    int sizeobr;

public:
     generator (QVector<char> , int ,int );
     QVector<QVector<char>> get_robr();
};

#endif // GENERATOR_H


