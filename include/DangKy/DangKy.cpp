#include"DangKy.h"
#include<iostream>
Register::Register(char* MASV, float DIEM){
    MASV_ = MASV;
    DIEM_ = DIEM;
    std::cout << "DA THEM SINH VIEN VAO DANH SACH LOP\n";
}
char* Register::get_MASV(){
    return MASV_;
}
float  Register::get_DIEM(){
    return DIEM_;
}
void Register::info(){
    std::cout << MASV_ << " " << DIEM_ << '\n';
}