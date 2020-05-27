#include "library.h"

void DSLopTC_HUY(DanhSachLopTC& dsltc){
    for(int i=0;i<dsltc.getN();i++){
        LopTC loptc;
        loptc = *dsltc.node[i];
        if(loptc.huylop){
            std::cout << dsltc.node[i]->malop;
        }
    }
}

bool HuyLopTC(DanhSachLopTC& dsltc,int ma_lop){
    for(int i=0;i<dsltc.getN();i++){
        LopTC loptc;
        loptc = *dsltc.node[i];
        if(loptc.malop == ma_lop){
            dsltc.xoaLop(ma_lop);
            return 1;
        }
    }
    return 0;
}

