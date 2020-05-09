#include "library.h"

void Show_Student(DanhSachSinhVien dssv){
    dssv.sort();
    Node * node = dssv.head();
    while(node->get_next()!=NULL){
        node->get_data().info();
        std::cout << '\n';
        node=node->get_next();
    }
}
