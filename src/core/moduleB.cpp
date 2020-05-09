#include "library.h"


void ModuleB(short nienkhoa, short hocki, short nhom, char maMH[]){
    LOPTC DSLTC;
    DSLTC.khoiTaoDS();
    DSLTC.get_from_file(DSLTC_PATH__);
    
    for(int i=0;i<DSLTC.getN();i++){
        Lop DSLOP;
        DSLOP = *DSLTC.node[i];
        if(DSLOP.nienkhoa == nienkhoa && DSLOP.hocki == hocki && DSLOP.nhom == nhom && strcmp(DSLOP.maMH, maMH)==0){
            LinkedList<Register> listRegister =  DSLOP.dsdk;
            Node<Register>* node = listRegister.head();
            while(node->get_next()!=NULL){
                node->get_data().info();
                std::cout<<"\n";
            }
        }
    }
}
