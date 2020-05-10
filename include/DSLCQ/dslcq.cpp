#include "dslcq.h"

/************************** LopCQ *****************************/
LopCQ::LopCQ(char * malop) {
  MALOP = malop;
  DSSV = new DanhSachSinhVien();
}

/*********************** DanhSachLopCQ ************************/

DanhSachSinhVien * DanhSachLopCQ::get_dssv(char * malop) {
  Node<LopCQ> * temp = p_head_;
  
  while (temp != NULL && temp->get_data().MALOP != malop) {
    temp = temp->get_next();
  }
  
  if (temp == NULL) 
    return NULL;
  return temp->get_data().DSSV;
}

void DanhSachLopCQ::save_to_file(char * file_path) {

}

void DanhSachLopCQ::get_from_file(char * file_path) {

}
