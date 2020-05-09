#include "library.h"

void them_sv(DanhSachSinhVien& dssv, char * MaLopCQ){
    std::cout << "Nhap thong tin sinh vien\n";
    
    char MASV[15]; 
    char * HO;
    char * TEN;
    char * SDT;
    bool PHAI;

    std::cout << "Nhap ma sinh vien: "; std::cin >> MASV;
    std::cout << "Nhap ho: "; std::cin >> HO;
    std::cout << "Nhap ten: "; std::cin >> TEN;
    std::cout << "Nhap so dien thoai"; std::cin >> SDT;
    std::cout << "Nhap gioi tinh: "; std::cin >> PHAI;
    
    SinhVien sv(MASV, HO, TEN, PHAI, SDT, MALOP);
    dssv.push_back(sv);
}

