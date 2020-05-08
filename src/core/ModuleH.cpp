#include "library.h"


void huyLopTC(LOPTC& BASE_DSLTC){
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
