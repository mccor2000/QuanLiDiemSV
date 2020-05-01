#include"DangKy.h"
#include<iostream>
Register::Register(char* MASV, short DIEM){
    MASV_ = MASV;
    DIEM_ = DIEM;
    std::cout << "DA THEM SINH VIEN VAO DANH SACH LOP\n";
}
char* Register::get_MASV(){
    return MASV_;
}
short  Register::get_DIEM(){
    return DIEM_;
}