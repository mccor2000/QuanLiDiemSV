#include "library.h"


void huyLopTC(){
    LOPTC BASE_DSLTC;
    BASE_DSLTC.khoiTaoDS();
    BASE_DSLTC.get_from_file(DSLTC_PATH__);
    for(int i=0;i<BASE_DSLTC.getN();i++){
        Lop LOP;
        LOP = *BASE_DSLTC.node[i];
        if(LOP.huylop){
            BASE_DSLTC.xoaLop(BASE_DSLTC.node[i]->malop);
        }
    }
}

int main(){
    std::cout << "Module H\n";
}
