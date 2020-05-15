#include "library.h"

void print_mh(MonHoc x) {
  std::cout << x.MAMH << " " << x.TENMH << " " << x.STCLT << " " << x.STCTH << "\n";
}

void print_dsmh(DanhSachMonHoc& dsmh) {
  dsmh.enumerate(print_mh);
}

