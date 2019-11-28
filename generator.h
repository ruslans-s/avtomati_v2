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
    int sizetext;

public:
     generator (QVector<char> , int ,int,int );
     QVector<QVector<char>> get_robr();
     QVector<char> getText();
};

#endif // GENERATOR_H


