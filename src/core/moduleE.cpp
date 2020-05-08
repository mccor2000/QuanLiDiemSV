#include "library.h"

void create_mh() {
  char ma_mh[10];
  char ten_mh[10];
  int stclt;
  int stcth;
  
  // Input 
  std::cout << "Nhap ma mon hoc: "; std::cin >> ma_mh;
  std::cout << "Nhap ten mon hoc: "; std::cin >> ten_mh;
  std::cout << "Nhap so tin chi ly thuyet: "; std::cin >> stclt;
  std::cout << "Nhap so tin chi thuc hanh: "; std::cin >> stcth;
  
  // Get data
  DanhSachMonHoc dsmh;
  dsmh.get_from_file(DSMH_PATH__);
  
  // Insert mh
  MonHoc new_mh(ma_mh, ten_mh, stclt, stcth);
  dsmh.insert(new_mh);

  // Save data
  dsmh.save_to_file(DSMH_PATH__);
}

void update_mh() {
  // Get ten_mh
  char ten_mh[50];
  std::cout << "Nhap ten mon hoc can hieu chinh: "; std::cin >> ten_mh;
  
  // Get mh
  DanhSachMonHoc dsmh;
  dsmh.get_from_file(DSMH_PATH__);
  node * temp = dsmh.search(ten_mh);
  
  // Delete mh
  dsmh.remove(temp->key);

  // Create new mh
  create_mh();
}

void delete_mh() {
  // Get input
  char ten_mh[50];
  std::cout << "Nhap ten mon hoc can xoa: "; std::cin >> ten_mh;
  
  // Get mh
  DanhSachMonHoc dsmh;
  dsmh.get_from_file(DSMH_PATH__);
  node * temp = dsmh.search(ten_mh);

  // Delete mh  
  dsmh.remove(temp->key);
}
