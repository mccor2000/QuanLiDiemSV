#include "library.h"

void in_dsmh(DanhSachMonHoc& dsmh) {
  dsmh.enumerate([](MonHoc x) {
    std::cout << x.MAMH << " " << x.TENMH << " " << x.STCLT << " " << x.STCTH << "\n";
  });
}

