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

/**************** DanhSachSinhVienDK ********************/

DanhSachSinhVienDK::DanhSachSinhVienDK() {
  p_head_ = NULL;
  p_tail_ = NULL;
}

SinhVienDK DanhSachSinhVienDK::get_by_index(int index){
  Node<SinhVienDK>* node = head();
  SinhVienDK result;
  if(index>count()){
    return result;
  }
  while(node!=NULL && index--){
    node=node->get_next();
  }
  result=node->get_data();
  return result;
}

void DanhSachSinhVienDK::save(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dsdk/";
  strcat(path, ma_lop);
  strcat(path, ".d");
  // Open file
  std::ofstream f;
<<<<<<< HEAD
  f.open(path, std::ios::binary);
  // Write file
  Node<SinhVienDK> * current_node = p_head_;
  while (current_node != NULL) {
    SinhVienDK current_sv = current_node->get_data();
    f.write((char *)&current_sv, sizeof(SinhVienDK));
=======
  f.open(path, std::ios::out);
  
  // Save to file
  Node<SinhVienDK>  * temp_node = p_head_;

  while (temp_node != NULL) {
    f<<temp_node->get_data().get_MASV()<<"\t"
     <<temp_node->get_data().get_DIEM()<<"\n";
>>>>>>> 274d1a2201193053cbaa8575136a5941269a95c7

    current_node = current_node->get_next();
  }
  // Save file
  f.close();
}

void DanhSachSinhVienDK::load(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dsdk/";
  strcat(path, ma_lop);
  strcat(path, ".d");
  // Open file
  std::ifstream f;
<<<<<<< HEAD
  f.open(path, std::ios::binary);
  // Read file 
  SinhVienDK temp;
  while (f.read((char *)&temp, sizeof(SinhVienDK))) {
    push_back(temp);
  }
  // Save file
  f.close();
}
=======
  f.open(path, std::ios::in);
  
  // Read from file 
  char ma[15]; //masv
  int d;       //diem
  while (f>>ma>>d) {
    SinhVienDK svdk(ma,d);
    push_back(svdk); // bug hereeeeeee
  }

  // Close file
  f.close();
}

SinhVienDK DanhSachSinhVienDK::get_by_index(int index){
  Node<SinhVienDK>* node = head();
  SinhVienDK result;
  if(index>count()){
    return result;
  }
  while(node!=NULL && index--){
    node=node->get_next();
  }
  result=node->get_data();
  return result;
}
>>>>>>> 274d1a2201193053cbaa8575136a5941269a95c7

