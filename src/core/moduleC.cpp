#include "library.h"

void them_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);
  
  if (dssv == NULL) {
    std::cout << "Lớp không tồn tại\n";
    return;
  }
  // Nhap sv
  // ...
}

void xoa_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);

  if (dssv == NULL) {
    std::cout << "Lớp không tồn tại\n";
    return;
  }
  // Xoa sv
  // ...
}

void hieu_chinh_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);

  if (dssv == NULL) {
    std::cout << "Lớp không tồn tại\n";
    return;
  }
  // Hieu chinh sv
  // ...
}

