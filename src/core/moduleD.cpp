#include "library.h"

void in_danh_sach_sv(DanhSachLopCQ DSLCQ, char * ma_lop) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);
  
  if (dssv == NULL) {
    std::cout << "Lớp không tồn tại\n";
    return;
  }
  // In danh sach sv
  // ...
}
