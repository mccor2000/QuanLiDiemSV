#include "dsdk.h"
/********************* SinhVienDK ********************/

//-- Constructor
SinhVienDK::SinhVienDK(char* MASV, short DIEM){
    MASV_ = MASV;
    DIEM_ = DIEM;
    std::cout << "DA THEM SINH VIEN VAO DANH SACH LOP\n";
}

//-- Getters, setters
char * SinhVienDK::get_MASV(){
  return MASV_;
}

short SinhVienDK::get_DIEM(){
  return DIEM_;
}

void SinhVienDK::set_MASV(char * masv) {
  MASV_ = masv;  
}

void SinhVienDK::set_DIEM(short diem) {
 DIEM_ = diem;
}

//-- Methods
void SinhVienDK::info() {
    std::cout << MASV_ << " " << DIEM_ << '\n';
}

/**************** DanhSachSinhVienDK ********************/

void DanhSachSinhVienDK::print() {
  std::cout << "MASV\tDIEM\n";
  Node * temp = p_head_;
  
  while (temp != NULL) {
    std::cout << temp->get_data().get_MASV() << "\t" << temp->get_data().get_MASV() << "\n";
    temp = temp->get_next();
  }
}

void DanhSachSinhVienDK::save_to_file(char * file_path) {
  std::ofstream f;
  f.open(file_path, std::ios::binary);

  Node * temp_node = p_head_;
  do {
      SinhVienDK temp_sv = temp_node->get_data();
      f.write((char *)&temp_sv, sizeof(SinhVienDK));    
      temp_node = temp_node->get_next();
  } while (temp_node->get_next() != NULL);
  
  f.close();
}

void DanhSachSinhVienDK::get_from_file(char * file_path) {
  std::ifstream f;
  f.open(file_path, std::ios::binary);
  
  SinhVienDK temp;
  while (f.read((char *)&temp, sizeof(SinhVienDK))) {
    push_back(temp);
  }
  
  f.close();
}

