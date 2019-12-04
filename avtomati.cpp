#include "avtomati.h"

avtomati::avtomati()
{

}
void avtomati::setSizeVec(int size) {
        perex.resize(size);//Установка длины масива переходов
    }
void avtomati::setPVec(QVector<QChar> tperex) {
        pperex = tperex; //Сохрание входяшей последовательности
    }
void avtomati::setPer(QVector<int> nper) {
        perex = nper; //Запись переходов
    }
QVector<int> avtomati::getPvec() {
        return perex; // Возврат массива переходов
    }
QVector<QChar> avtomati::getPPvec() {
        return pperex; // Возврат входящей последовательности
    }

void avtomati::setnumberobr(int newnumberobraz) {
        numberobraz = newnumberobraz; //Установка номера образца
    }
int avtomati::getnumberobr() {
        return numberobraz; //Возврат номера образца
    }
void avtomati::setfinal(){
        final=true; //установка того что состояние является финальным
}
bool avtomati::getfinal(){
    return final; //Возврат состояния
}
