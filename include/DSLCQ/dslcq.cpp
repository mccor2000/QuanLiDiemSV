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
  Node<LopCQ> * curr_lopcq = p_head_;
  while (curr_lopcq != NULL) {
    // Save MALOP
    char * ma_lop = curr_lopcq->get_data().MALOP;
    f.write((char *)ma_lop, sizeof(char[15]));
    // Save DSSV
    curr_lopcq->get_data().DSSV->save(ma_lop);
    curr_lopcq = curr_lopcq->get_next();
  }
  // Close file
  f.close();
}

void DanhSachLopCQ::load() {
  // Open file
  std::ifstream f;
  f.open(db, std::ios::binary);
  
  // Load
  char curr_malop[15]; 
  while (f.read((char *)curr_malop, sizeof(char[15]))) {
    LopCQ curr_lopcq(curr_malop);
    curr_lopcq.DSSV->load(curr_malop);
    push_back(curr_lopcq);
  }
  // Close file 
  f.close();
}

LopCQ DanhSachLopCQ::get_by_index(int index){
  Node<LopCQ>* node = head();
  LopCQ result;
  if(index>count()){
    return result;
  }
  index--;
  while(node!=NULL && index--){
    node=node->get_next();
  }
  result=node->get_data();
  return result;
}