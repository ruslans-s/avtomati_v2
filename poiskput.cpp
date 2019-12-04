#include "poiskput.h"
#include "avtomati.h"
poiskput::poiskput(QVector <QChar> Falphab, QVector <avtomati>& Favtomvec, QVector<QVector<QChar>> Fobraz, int r2)
{
        int r9 = 0;

        QVector<QChar> tempvec;

        for (int i = 0; i <= Falphab.size() - 1; ++i) {
            for (int j = 0; j <= Fobraz.size() - 1; ++j) {
                if (Falphab[i] == Fobraz[j][r2]) {
                    //++r1;
                    tempvec = Fobraz[j];
                    tempvec.resize(r2 + 1);                
                    Favtomvec.resize(Favtomvec.size() + 1);
                    Favtomvec[Favtomvec.size() - 1].setSizeVec(Falphab.size());
                    Favtomvec[Favtomvec.size() - 1].setPVec(tempvec);
                    Favtomvec[Favtomvec.size() - 1].setnumberobr(j);

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
