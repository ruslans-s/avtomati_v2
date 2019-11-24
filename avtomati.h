#ifndef AVTOMATI_H
#define AVTOMATI_H
#include <QVector>

class avtomati
{
private:
    QVector<int> perex; //Список переходов
    QVector<char> pperex; // последовательность входяшая в автомат
    int numberobraz; // Номер образца из которого получили последовательность, нужно для нахождения путей
    bool final=false; // Является ли автомат финальным в своей последовательности
public:
    avtomati();
    void setSizeVec(int);
    void setPVec(QVector<char> );
    void setPer(QVector<int> ) ;
    QVector<int> getPvec() ;
    QVector<char> getPPvec();
    void setnumberobr(int) ;
    int getnumberobr();
    void setfinal();
    bool getfinal();
};

#endif // AVTOMATI_H
