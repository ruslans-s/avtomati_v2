#include "poiskperexod.h"
#include<QVector>
#include <algorithm>
poiskperexod::poiskperexod(QVector<avtomati>& avtomvec,QVector<char> alphab)
{
    Tintvec.resize(alphab.size());
    QVector<int> TintvecN = Tintvec;
    bool itfin1,itfin2;
    for (int rf3 = 0; rf3 <= avtomvec.size() - 1; ++rf3) {

           // itfin1=false;
            itfin1 = avtomvec[rf3].getfinal();
            if(rf3>0){
            tvec5 = avtomvec[rf3].getPPvec();}
            else{
                tvec5={};
            }

            for (int rf4 = 0; rf4 <= alphab.size() - 1; rf4++) {
                tvec2 = tvec5;
                tvec2.push_back(alphab[rf4]);
             /*  tvec2t=tvec2;

                for(int rr2=tvec2.size()-1;rr2>=0;rr2--){
                   tvec2t[tvec2.size()-rr2-1]=(tvec2[rr2]);
                }*/

               // reverse(tvec2.begin(), tvec2.end());
                  oldmax = 0;
                for (int rf5 = 0; rf5 <= avtomvec.size() - 1; ++rf5) {
                    itfin2 = avtomvec[rf5].getfinal();
                    if(itfin1==true && itfin2==true){
                        continue;
                    }
                    tvec3 = tvec2;
                    tvec4 = avtomvec[rf5].getPPvec();
                        //
                        if (tvec3.size() > tvec4.size()) {
                           // tvec3.resize(tvec4.size());
                            while (tvec3.size() > tvec4.size()){
                                tvec3.pop_front();
                            }
                    }
                        if (tvec4.size() > tvec3.size()) {
                            tvec4.resize(tvec3.size());

                    }

                    cr1 = tvec3[0];
                    cr2 = tvec4[0];
                    if ( (rf5 != rf3) && (cr1==cr2) ){

                        max = 0;
                        for (int rf6 = 0; rf6 <= tvec3.size()-1; ++rf6) {
                            if (tvec3 == tvec4) {

                                max=tvec3.size();


                            } else {
                             tvec3.pop_front();
                             tvec4.pop_back();
                            //break;

                            }
                        }


                        }

                    if (max >> oldmax) {
                        oldmax = max;
                        Tintvec[rf4] = rf5;
                        max = 0;

                    }


                    }
                }

            avtomvec[rf3].setPer(Tintvec);
            Tintvec = TintvecN;
          //  Tintvec.assign();
        }


}
