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
    DS_LOPTC = new LinkedList<int>;
}

SinhVien::SinhVien() {
  strcpy(MASV_, "");
  DS_LOPTC = new LinkedList<int>;
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

SinhVien DanhSachSinhVien::get_sv(char * ma_sv) {
  // Find
  Node<SinhVien> * curr_node = p_head_;
  while(curr_node != NULL &&
        strcmp(curr_node->get_data().get_MASV(), ma_sv) != 0)
  {
    curr_node = curr_node->get_next();
  }
  // Return
  return curr_node->get_data();
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

void DanhSachSinhVien::save(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dssv/";
  strcat(path, ma_lop);
  strcat(path, ".txt");

  // Open file
  std::ofstream f;
  f.open(path, std::ios::out);

  // Loop through the list and write to file 
  Node<SinhVien> * curr_node = head();
  while (curr_node != NULL) {
    SinhVien sv = curr_node->get_data();
    f << sv.get_MASV() << "\n" 
      << sv.get_HO() << "\n" 
      << sv.get_TEN() << "\n" 
      << sv.get_PHAI() << "\n" 
      << sv.get_SDT() << "\n" 
      << sv.get_MALOP() <<"\n";

    f << sv.DS_LOPTC->count() << "\n";
    Node<int> * curr_ma_ltc = sv.DS_LOPTC->head();
    while (curr_ma_ltc != NULL) {
      f << curr_ma_ltc->get_data() << "\t";
      curr_ma_ltc = curr_ma_ltc->get_next();
    }
    f << "\n";
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
  std::string masv_str;
  std::string ho_str;
  std::string ten;
  std::string malop;
  bool phai;
  std::string sdt;
  
  while (getline(f,masv_str)) {
    getline(f,ho_str);
    getline(f,ten);
    f >> phai;
    std::string tmp;
    getline(f,tmp);
    getline(f,sdt);
    getline(f,malop);

    SinhVien curr_sv((char*) masv_str.c_str(),(char*) ho_str.c_str(),(char*) ten.c_str(),phai,(char*)sdt.c_str(),(char*)malop.c_str());
    
    int num_of_loptc;
    f >> num_of_loptc;
    getline(f,tmp);
    for (int i = 0; i < num_of_loptc; i++) {
      int curr_ma_ltc;
      f >> curr_ma_ltc;
      curr_sv.DS_LOPTC->push_back(curr_ma_ltc); 
    }
    getline(f,tmp);
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
