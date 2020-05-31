#include "library.h"

LinkedList<char* []> DanhSachLopChinhQuy(DanhSachLopCQ& dslcq){
    LinkedList<char *> result;
    Node<LopCQ>* node = dslcq.head();
    while(node != NULL){
        char buffer[30];
        char* res[2];
        strcpy(node->get_data().MALOP,res[0]);
        res[1]="DSSV";
        result.push_back(res);
        node=node->get_next();
    }
    return result;
} 
