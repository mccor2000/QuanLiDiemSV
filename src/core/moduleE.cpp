#include "library.h"

void create_mh(DanhSachMonHoc& dsmh) {
  char ma_mh[10];
  char ten_mh[10];
  int stclt;
  int stcth;
  
  // Input 
  std::cout << "Nhap ma mon hoc: "; std::cin >> ma_mh;
  std::cout << "Nhap ten mon hoc: "; std::cin >> ten_mh;
  std::cout << "Nhap so tin chi ly thuyet: "; std::cin >> stclt;
  std::cout << "Nhap so tin chi thuc hanh: "; std::cin >> stcth;
  
  // Insert mh
  MonHoc new_mh(ma_mh, ten_mh, stclt, stcth);
  dsmh.insert(new_mh);
}

void update_mh(DanhSachMonHoc& dsmh) {

}

void delete_mh(DanhSachMonHoc& dsmh) {
  
}
