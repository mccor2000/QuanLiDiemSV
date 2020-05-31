#include "library.h"

// LinkedList<char*> DSLopTC_HUY(){
//     LinkedList<char*> result;

//     for(int i=0;i<dsltc.getN();i++){
//         LopTC loptc;
//         loptc = *dsltc.node[i];
//         if(loptc.huylop){
//             result.push_back(converting(dsltc.node[i]->malop));
//         }
//     }
//     return result;
// }

bool HuyLopTC(int ma_lop){
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
