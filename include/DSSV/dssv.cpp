#include "dssv.h"

/************************ SinhVien ****************************/

//-- Constructor
SinhVien::SinhVien(char* MASV,char* HO,char* TEN,bool PHAI, char* SDT,char* MALOP){
    strcpy(MASV_, MASV);
    strcpy(HO_, HO);
    strcpy(TEN_, TEN);
    PHAI_ = PHAI;
    strcpy(SDT_, SDT);
    strcpy(MALOP_, MALOP);
}

//-- Methods
void SinhVien::print_info(WINDOW * curr_win){
  mvwprintw(curr_win, 1, 1, MASV_);
  mvwprintw(curr_win, 2, 1, HO_);
  mvwprintw(curr_win, 3, 1, TEN_);
  mvwprintw(curr_win, 4, 1, (PHAI_) ? "Nam" : "Nu");
  mvwprintw(curr_win, 5, 1, SDT_);
  mvwprintw(curr_win, 6, 1, MALOP_);
}

//-- Operator overloading
bool SinhVien::operator > (SinhVien x) {
    return (strcmp(TEN_, x.TEN_) > 0);
}

bool SinhVien::operator < (SinhVien x) {
    return (strcmp(TEN_, x.TEN_) < 0);
}

bool SinhVien::operator == (SinhVien x) {
    return (strcmp(MASV_, x.MASV_) == 0);
}


/********************** DanhSachSinhVien ***********************/
SinhVien * DanhSachSinhVien::search_sv(char * ma_sv) {
  // Find
  Node<SinhVien> * curr_node = p_head_;
  SinhVien sv;
  while(curr_node != NULL &&
        strcmp(curr_node->get_data().get_MASV(), ma_sv) != 0)
  { 
    sv = curr_node->get_data();
    curr_node = curr_node->get_next();
  }
  // Return
  if (curr_node == NULL) return NULL;
  return &sv;
}

void DanhSachSinhVien::delete_sv(char * ma_sv) {
  Node<SinhVien> * curr_node = p_head_;
  
  // If head
  if (curr_node == NULL) return;
  if (strcmp(curr_node->get_data().get_MASV(), ma_sv) == 0) {
    p_head_ = curr_node->get_next();
    delete curr_node;
    return;
  }

  do {
    if (strcmp(curr_node->get_next()->get_data().get_MASV(), ma_sv) == 0) {
      Node<SinhVien> * temp = curr_node->get_next();
      if (curr_node->get_next() != p_tail_) {
        // Normal node
        curr_node->set_next(curr_node->get_next()->get_next());
      } else {
        // If tail
        p_tail_ = curr_node;
      }
      delete temp;
      return;
    }
    curr_node = curr_node->get_next();
  } while (curr_node != NULL);
}

void DanhSachSinhVien::save(char * ma_lop) {
  // Get path
  char path[64] = "../../database/dssv/";
  strcat(path, ma_lop);
  strcat(path, ".d");

  // Open file
  std::ofstream f;
  f.open(path, std::ios::binary);

  // Loop through the list and write to file 
  Node<SinhVien> * curr_node= p_head_;
  while (curr_node != NULL) {
    SinhVien curr_sv= curr_node->get_data();
    f.write((char *)&curr_sv, sizeof(SinhVien));

    curr_node = curr_node->get_next();
  }
  // Close file
  f.close();
}

void DanhSachSinhVien::load(char * ma_lop) {
  // Get path
  char path[64] = "../../database/dssv/";
  strcat(path, ma_lop);
  strcat(path, ".d");
  
  // Open file
  std::ifstream f;
  f.open(path, std::ios::binary);
  
  // Get data from file and push to the list
  SinhVien curr_sv;
  while (f.read((char *)&curr_sv, sizeof(SinhVien))) {
    push_back(curr_sv);
  }
  // Close the file
  f.close();
}

SinhVien DanhSachSinhVien::get_by_index(int index){
  Node<SinhVien>* node = head();
  SinhVien result;
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