#include "library.h"

void Add(DanhSachSinhVien& dssv, char * MaLopCQ){
    std::cout << "Nhap thong tin sinh vien\n";
    
    char* MASV="TEST"; 
    char* HO="TEST";
    char* TEN="TEST";
    char* SDT="TEST";
    char* MALOP="TEST";
    bool PHAI=1;
    
    SinhVien sv(MASV, HO, TEN, PHAI, SDT, MALOP);
    dssv.push_back(sv);
}
