#include "library.h"

LinkedList<char* > DanhSachLopChinhQuy(DanhSachLopCQ& dslcq){
    LinkedList<char *> result;
    Node<LopCQ>* node = dslcq.head();

    char * res;
    while(node != NULL){
        strcpy(res, node->get_data().MALOP);
        strcat(res, (char *)"DSSV");
        result.push_back(res);
        node=node->get_next();
    }
    return result;
} 
