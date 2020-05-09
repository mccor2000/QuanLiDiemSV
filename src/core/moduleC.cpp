#include "library.h"

void Add(LinkedList<lopCQ>& DSLCQ, char* MaLopCQ){
    Node<lopCQ>* node_CQ = DSLCQ.head();
    bool flag = false; // finding variable
    while(node_CQ->get_next() != NULL){
        if(node_CQ->get_data().get_MALOP() == MaLopCQ){
            flag=true;
            break;
        }
        node_CQ = node_CQ->get_next();
    }
    if(flag){
        char* ten="test";
        Student sv(ten,ten,ten,true,ten,ten);
        node_CQ->get_data().get_DSSV().push_back(sv);
    }
}

