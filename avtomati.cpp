#include "avtomati.h"

avtomati::avtomati()
{

}
void avtomati::setSizeVec(int size) {
        perex.resize(size);
    }
void avtomati::setPVec(QVector<char> tperex) {
        //pperex.resize(size);
        pperex = tperex;
    }
void avtomati::setPer(QVector<int> nper) {
        perex = nper;
    }
QVector<int> avtomati::getPvec() {
        return perex;
    }
QVector<char> avtomati::getPPvec() {
        return pperex;
    }

void avtomati::setnumberobr(int newnumberobraz) {
        numberobraz = newnumberobraz;
    }
int avtomati::getnumberobr() {
        return numberobraz;
    }
void avtomati::setfinal(){
        final=true;
}
bool avtomati::getfinal(){
    return final;
}
