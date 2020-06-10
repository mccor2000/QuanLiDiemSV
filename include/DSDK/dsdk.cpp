#include "dsdk.h"
/********************* SinhVienDK ********************/

//-- Constructor
SinhVienDK::SinhVienDK(char * MASV, float DIEM){
    strcpy(MASV_, MASV);
    DIEM_ = DIEM;
}

SinhVienDK::SinhVienDK(char * MASV) {
    strcpy(MASV_, MASV);
    DIEM_ = 0;
}

//-- Getters, setters
char * SinhVienDK::get_MASV(){
  return MASV_;
}

float SinhVienDK::get_DIEM(){
  return DIEM_;
}

void SinhVienDK::set_MASV(char * masv) {
    strcpy(MASV_, masv);
}

void SinhVienDK::set_DIEM(float diem) {
 DIEM_ = diem;
}

/**************** DanhSachSinhVienDK ********************/

DanhSachSinhVienDK::DanhSachSinhVienDK() {
  p_head_ = NULL;
  p_tail_ = NULL;
}

void DanhSachSinhVienDK::save(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dsdk/";
  strcat(path, ma_lop);
  strcat(path, ".txt");
  // Open file
  std::ofstream f;
  f.open(path, std::ios::out);
  
  // Save to file
  Node<SinhVienDK>  * temp_node = p_head_;

  while (temp_node != NULL) {
    f<<temp_node->get_data().get_MASV()<<"\t"
     <<temp_node->get_data().get_DIEM()<<"\n";

    temp_node = temp_node->get_next();
  }
  // Save file
  f.close();
}

void DanhSachSinhVienDK::load(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dsdk/";
  strcat(path, ma_lop);
  strcat(path, ".txt");
  // Open file
  std::ifstream f;
  f.open(path, std::ios::in);
  
  // Read from file 
  char ma[15]; //masv
  int d;       //diem
  while (f>>ma>>d) {
    SinhVienDK svdk(ma,d);
    push_back(svdk);
  }

  // Close file
  f.close();
}

Node<SinhVienDK> * DanhSachSinhVienDK::get_node_by_index(int index){
  if (index > count()) return NULL;

  Node<SinhVienDK> * current_node = p_head_;
  int i = 0;
  while (current_node != NULL && i < index) {
    current_node = current_node->get_next();
    i++;
  }
  return current_node;
}
