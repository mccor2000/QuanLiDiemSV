#include "SinhVien.h"
#include <iostream>

char* Student::get_MASV(){
    return MASV_; 
}
char* Student::get_HO(){
    return HO_; 
}
char* Student::get_TEN(){
    return TEN_; 
}
char* Student::get_SDT(){
    return SDT_; 
}
char* Student::get_MALOP(){
    return MALOP_; 
}
bool Student::get_PHAI(){
    return PHAI_;
}

Student::Student(char* MASV,char* HO,char* TEN,bool PHAI, char* SDT,char* MALOP){
    MASV_ = MASV;
    HO_ = HO;
    TEN_ = TEN;
    PHAI_ = PHAI;
    SDT_ = SDT;
    MALOP_ = MALOP;
    std::cout << "DA KHOI TAO 1 SINH VIEN\n"; 
}