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
  char path[64] = "../database/dslcq.txt";
  // Open file
  std::ofstream file;
  file.open(path, std::ios::out);

  Node<LopCQ> *curr_node = head();
  while(curr_node!=NULL){
    file<<curr_node->get_data().MALOP << "\n";
    curr_node=curr_node->get_next();
  }
  file.close();
}

void DanhSachLopCQ::load() {
  // Open file
   char path[64] = "../database/dslcq.txt";
  // Open file
  std::ifstream file;
  file.open(path, std::ios::in);
  char ma_lop[15];
  while(file>>ma_lop){
    LopCQ curr(ma_lop);
    push_back(curr);
  }
    file.close();
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
