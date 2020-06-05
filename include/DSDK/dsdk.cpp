RRnclude "dsdk.h"
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

void DanhSachSinhVienDK::save(const char * ma_lop) {
  // Get path
  char path[64] = "../database/dsdk/";
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
  char path[64] = "../database/dsdk/";
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

