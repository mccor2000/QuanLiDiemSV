#include "library.h"

void Show_Student(LinkedList<lopCQ>& LOPCQ, char* MALOP){
    Node<lopCQ>* node_CQ = LOPCQ.head();
    bool flag=false;
    while(node_CQ->get_next()!=NULL){
        if(node_CQ->get_data().get_MALOP() == MALOP){
            flag=true;
            break;
        }
        node_CQ= node_CQ->get_next();
    }
    if(flag){
        LinkedList<Student> dssv = node_CQ->get_data().get_DSSV();
        dssv.sort();
        Node<Student>* node_SV = dssv.head();
        while(node_SV->get_next()!=NULL){
            node_SV->get_data().info();
            std::cout<<'\n';
            node_SV=node_SV->get_next();
        }
        return;
    }
    std::cout << "Lop khong ton tai\n";
}
