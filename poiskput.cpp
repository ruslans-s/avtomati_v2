#include "poiskput.h"
#include "avtomati.h"
poiskput::poiskput(QVector <QChar> Falphab, QVector <avtomati>& Favtomvec, QVector<QVector<QChar>> Fobraz, int r2)
{
        int r9 = 0;
        //cout << "Vxod v Poisk" << endl; //Debug info
        QVector<QChar> tempvec;
        //int r1 = 0;
        for (int i = 0; i <= Falphab.size() - 1; ++i) {
            for (int j = 0; j <= Fobraz.size() - 1; ++j) {
                if (Falphab[i] == Fobraz[j][r2]) {
                    //++r1;

                    //cout << "Naiden" << i << endl; // Debug info

                    tempvec = Fobraz[j];
                    tempvec.resize(r2 + 1);
                    //Favtomvec.push_back(tempvec);
                    Favtomvec.resize(Favtomvec.size() + 1);
                    Favtomvec[Favtomvec.size() - 1].setSizeVec(Falphab.size());
                    Favtomvec[Favtomvec.size() - 1].setPVec(tempvec); // Придумать как передать часть образдца r2 до J
                    Favtomvec[Favtomvec.size() - 1].setnumberobr(j);
                    //Костыль
                    r9 = 0;
                    if (r2 > 0) {
                        for (int rf1 = 0; rf1 <= Fobraz.size()-1; ++rf1)
                        {
                            if (Fobraz[rf1][r2 - 1] == Fobraz[j][r2 - 1]) ++r9;
                        }
                        if (r9 == Fobraz.size()) break;
                    }
                    else break;

                }
            }
        }
}
