#ifndef GENERATOR_H
#define GENERATOR_H
#include <QVector>

class generator
{
protected:
    QVector<QVector<QChar>> GObraz;
    QVector<QChar> Talph;
    int numberobr;
    int sizeobr;
    int sizetext;

public:
     generator (QVector<QChar> , int ,int,int );
     QVector<QVector<QChar>> get_robr();
     QVector<QChar> getText();
};

#endif // GENERATOR_H


