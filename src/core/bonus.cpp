#include "library.h"


LinkedList<char* > DanhSachLopChinhQuy(DanhSachLopCQ& dslcq){
    LinkedList<char *> result;
    Node<LopCQ>* node = dslcq.head();
    while(node != NULL){
        char buffer[30];
        char* res= "";
        strcpy(node->get_data().MALOP,res);
        strcat(res, "   ");
        strcat(res,"DSSV");
        result.push_back(res);
        node=node->get_next();
    }
    return result;
} 
