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

SinhVien::SinhVien() {
  strcpy(MASV_, "");
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
DanhSachSinhVien::DanhSachSinhVien() {
  p_head_ = NULL;
  p_tail_ = NULL;
}

// Node<SinhVien> * DanhSachSinhVien::search_sv(char * ma_sv) {
  // // Find
  // Node<SinhVien> * curr_node = p_head_;
  // while(curr_node != NULL &&
        // strcmp(curr_node->get_data().get_MASV(), ma_sv) != 0)
  // {
    // curr_node = curr_node->get_next();
  // }
  // // Return
  // return curr_node;
// }

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

void DanhSachSinhVien::save(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dssv/";
  strcat(path, ma_lop);
  strcat(path, ".txt");

  // Open file
  std::ofstream f;
  f.open(path, std::ios::out);

  // Loop through the list and write to file 
  Node<SinhVien> * curr_node= head();
  while (curr_node != NULL) {
    SinhVien sv = curr_node->get_data();
    f << sv.get_MASV() << "\t" << sv.get_HO() << "\t" << sv.get_TEN() << "\t" << sv.get_PHAI()  << "\t" << sv.get_SDT()  << "\t" << sv.get_MALOP() <<"\n";
    curr_node = curr_node->get_next();
  }
  // Close file
  f.close();
}

void DanhSachSinhVien::load(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dssv/";
  strcat(path, ma_lop);
  strcat(path, ".txt");
  
  // Open file
  std::ifstream f;
  f.open(path, std::ios::in);
  // Get data from file and push to the list
  char masv[15];
  char ho[16];
  char ten[16];
  char malop[15];
  bool phai;
  char sdt[15];
    
  while (f>>masv>>ho>>ten>>phai>>sdt>>malop) {
    SinhVien curr_sv(masv,ho,ten,phai,sdt,malop);
    push_back(curr_sv);
  }
  // Close the file
  f.close();
}

Node<SinhVien> * DanhSachSinhVien::get_node_by_index(int index){
  if (index > count()) return NULL;

  Node<SinhVien> * current_node = p_head_;
  int i = 0;
  while (current_node != NULL && i < index) {
    current_node = current_node->get_next();
    i++;
  }
  return current_node;
}
