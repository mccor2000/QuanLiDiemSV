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

void DanhSachLopCQ::save() {
  // Open file
  std::ofstream f;
  f.open(db, std::ios::binary);
  
  // Save  
  Node<LopCQ> * temp = p_head_;
  while (temp != NULL) {
    // Save MALOP
    char * ma_lop = temp->get_data().MALOP;
    f.write((char *)ma_lop, sizeof(char[15]));
    // Save DSSV
    temp->get_data().DSSV->save(ma_lop);
  }

  // Close file
  f.close();
}

void DanhSachLopCQ::load() {
  // Open file
  std::ifstream f;
  f.open(db, std::ios::binary);
  
  // Load
  char temp[15]; 
  while (f.read((char *)temp, sizeof(char[15]))) {
    LopCQ lopcq(temp);
    lopcq.DSSV->load(temp);
    push_back(lopcq);
  }

  // Close file 
  f.close();
}
