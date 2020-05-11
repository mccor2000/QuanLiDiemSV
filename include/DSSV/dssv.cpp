#include "dssv.h"

/************************ SinhVien ****************************/

//-- Getters, Setters
char * SinhVien::get_MASV(){
    return MASV_; 
}

char * SinhVien::get_HO(){
    return HO_; 
}

char * SinhVien::get_TEN(){
    return TEN_; 
}

char * SinhVien::get_SDT(){
    return SDT_; 
}

char * SinhVien::get_MALOP(){
    return MALOP_; 
}

bool SinhVien::get_PHAI(){
    return PHAI_;
}

void SinhVien::set_MASV(char * masv) {
    strcpy(MASV_, masv);
}

void SinhVien::set_HO(char * ho) {
    strcpy(HO_, ho);
}

void SinhVien::set_TEN(char * ten) {
    strcpy(TEN_, ten);
}

void SinhVien::set_SDT(char * sdt) {
    strcpy(SDT_, sdt);
}

void SinhVien::set_MALOP(char * malop) {
    strcpy(MALOP_, malop);
}

void SinhVien::set_PHAI(bool phai) {
    PHAI_ = phai;
}

//-- Constructor
SinhVien::SinhVien(char* MASV,char* HO,char* TEN,bool PHAI, char* SDT,char* MALOP){
    strcpy(MASV_, MASV);
    strcpy(HO_, HO);
    strcpy(TEN_, TEN);
    PHAI_ = PHAI;
    strcpy(SDT_, SDT);
    strcpy(MALOP_, MALOP);
    std::cout << "DA KHOI TAO 1 SINH VIEN\n"; 
}

//-- Methods
void SinhVien::info(){
    std::cout << MASV_ << " " << HO_ <<  " " <<TEN_<< " "<< PHAI_ << " " << SDT_ << " " << MALOP_; 
}

//-- Operator overloading
bool SinhVien::operator > (SinhVien x) {
    return (strcmp(TEN_, x.TEN_) > 0);
}

bool SinhVien::operator < (SinhVien x) {
    return (strcmp(TEN_, x.TEN_) < 0);
}

bool SinhVien::operator == (SinhVien x) {
    return (strcmp(TEN_, x.TEN_) == 0);
}


/********************** DanhSachSinhVien ***********************/
void DanhSachSinhVien::save() {
  // Get path
  char path[64] = "../../database/dssv/";
  strcat(path, p_head_->get_data().get_MALOP());
  strcat(path, ".d");

  // Open file
  std::ofstream f;
  f.open(path, std::ios::binary);

  // Loop through the list and write to file 
  Node<SinhVien> * temp_node = p_head_;
  while (temp_node != NULL) {
    SinhVien temp_sv = temp_node->get_data();
    f.write((char *)&temp_sv, sizeof(SinhVien));

    temp_node = temp_node->get_next();
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
  SinhVien temp;
  while (f.read((char *)&temp, sizeof(SinhVien))) {
    push_back(temp);
  }

  // Close the file
  f.close();
}
