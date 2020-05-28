#include "dsdk.h"
/********************* SinhVienDK ********************/

//-- Constructor
SinhVienDK::SinhVienDK(char * MASV, float DIEM){
    strcpy(MASV_, MASV);
    DIEM_ = DIEM;
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

//-- Methods
void SinhVienDK::info() {
    std::cout << MASV_ << " " << DIEM_ << '\n';
}

/**************** DanhSachSinhVienDK ********************/

// void DanhSachSinhVienDK::print() {
//   std::cout << "MASV\tDIEM\n";
//   Node<SinhVienDK> * temp = p_head_;
  
//   while (temp != NULL) {
//     std::cout << temp->get_data().get_MASV() << "\t" << temp->get_data().get_DIEM() << "\n";
//     temp = temp->get_next();
//   }
// }

void DanhSachSinhVienDK::save(const char * ma_lop) {
  // Get path
  char path[64] = "../../database/dsdk/";
  strcat(path, ma_lop);
  strcat(path, ".d");
  
  // Open file
  std::ofstream f;
  f.open(path, std::ios::binary);
  
  // Write to file
  Node<SinhVienDK> * temp_node = p_head_;
  while (temp_node != NULL) {
    SinhVienDK temp_sv = temp_node->get_data();
    f.write((char *)&temp_sv, sizeof(SinhVienDK));    

    temp_node = temp_node->get_next();
  }
  
  // Save file
  f.close();
}

void DanhSachSinhVienDK::load(const char * ma_lop) {
  // Get path
  char path[64] = "../../database/dsdk/";
  strcat(path, ma_lop);
  strcat(path, ".d");
  
  // Open file
  std::ifstream f;
  f.open(path, std::ios::binary);
  
  // Read from file 
  SinhVienDK temp;
  while (f.read((char *)&temp, sizeof(SinhVienDK))) {
    push_back(temp);
  }
  
  // Save file
  f.close();
}

