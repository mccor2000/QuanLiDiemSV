#include "lopCQ.h"
#include <iostream>
#include "../templates/LinkedList.h"
#include "../SinhVien/SinhVien.h"

lopCQ::lopCQ(char* name, LinkedList<Student> dssv ){
    TenLop_ = name;
    DSSV_ = dssv;
    std:: cout << "Khoi tao thanh cong mot lop Chinh Quy\n";
}

char* lopCQ::get_TenLop(){
    return TenLop_;
}
LinkedList<Student> lopCQ::get_DSSV(){
    return DSSV_;
}
