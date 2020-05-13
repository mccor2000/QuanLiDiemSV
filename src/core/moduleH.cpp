#include "library.h"

void DSLopTC_HUY(LOPTC& BASE_DSLTC){
    for(int i=0;i<BASE_DSLTC.getN();i++){
        Lop LOP;
        LOP = *BASE_DSLTC.node[i];
        if(LOP.huylop){
            std::cout << BASE_DSLTC.node[i]->malop;
        }
    }
}

bool HuyLopTC(LOPTC& BASE_DSLTC,int ma_lop){
    for(int i=0;i<BASE_DSLTC.getN();i++){
        Lop LOP;
        LOP = *BASE_DSLTC.node[i];
        if(LOP.malop == ma_lop){
            BASE_DSLTC.xoaLop(ma_lop);
            return 1;
        }
    }
    return 0;
}

