#include "dslcq.h"

/************************** LopCQ *****************************/
LopCQ::LopCQ(char * malop) {
  MALOP = malop;
  DSSV = new DanhSachSinhVien();
}

/*********************** DanhSachLopCQ ************************/

LopCQ DanhSachLopCQ::get_lcq(char * malop) {
  Node<LopCQ> * curr_lopcq = p_head_;
  while (curr_lopcq!= NULL && curr_lopcq->get_data().MALOP != malop) {
    curr_lopcq = curr_lopcq->get_next();
  }
  
  return curr_lopcq->get_data();
}

DanhSachSinhVien * DanhSachLopCQ::get_dssv(char * malop) {
  Node<LopCQ> * curr_lopcq = p_head_;
  while (curr_lopcq!= NULL && curr_lopcq->get_data().MALOP != malop) {
    curr_lopcq = curr_lopcq->get_next();
  }
  
  if (curr_lopcq == NULL) return NULL;
  return curr_lopcq->get_data().DSSV;
}

SinhVien * DanhSachLopCQ::search_sv(char * ma_sv) {
  Node<LopCQ> * curr_lopcq = p_head_;
  SinhVien * res = NULL;
  while (curr_lopcq != NULL && !res) {
    // Search for every LopCQ
    res = curr_lopcq->get_data().DSSV->search_sv(ma_sv);
    curr_lopcq = curr_lopcq->get_next();
  }
  return res;
}

void DanhSachLopCQ::save() {
  // Open file
  std::ofstream f;
  f.open(db, std::ios::binary);
 
  // Save  
  Node<LopCQ> * current_node = p_head_;
  while (current_node != NULL) {
    LopCQ current_lopcq = current_node->get_data();
    std::string temp(current_lopcq.MALOP);
    // Save MALOP
    f.write((char *)&current_lopcq, sizeof(LopCQ));
    // Save DSSV
    current_lopcq.DSSV->save(temp.c_str());
    current_node = current_node->get_next();
  }
  // Close file
  f.close();
}

void DanhSachLopCQ::load() {
  // Open file
  std::ifstream f;
  f.open(db, std::ios::binary);
  
  // Load
  LopCQ * current_lopcq = new LopCQ();
  while (f.read((char *)current_lopcq, sizeof(LopCQ))) {
    std::string temp(current_lopcq->MALOP);
    current_lopcq->DSSV->load(temp.c_str());
    push_back(*current_lopcq);
  }
  // Close file 
  f.close();
}

Node<LopCQ> * DanhSachLopCQ::get_node_by_index(int index) {
  if (index > count()) return NULL;
  
  Node<LopCQ> * current_node = p_head_;
  int i = 0;
  while (current_node != NULL && i <= index) {
    current_node = current_node->get_next();
    i++;
  }
  return current_node;
}
