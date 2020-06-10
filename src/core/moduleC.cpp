#include "library.h"

void add_sv(char ** data) {
  strcpy(data[0],upper_case_letters(data[0]));
  strcpy(data[3],upper_case_letters(data[3]));
  strcpy(current_lopcq.MALOP,upper_case_letters(current_lopcq.MALOP));
  // Tao sinh vien
  SinhVien sv(
      data[0],
      data[1],
      data[2],
      strcmp(data[3],"NAM")==0 ? 0 : 1, 
      data[4],
      current_lopcq.MALOP
  );
  current_dssv->push_back(sv);
}

void update_sv(char ** data) {
  strcpy(data[0],upper_case_letters(data[0]));
  strcpy(data[3],upper_case_letters(data[3]));
  strcpy(current_lopcq.MALOP,upper_case_letters(current_lopcq.MALOP));
  current_sv->get_data().set_MASV(data[0]);
  current_sv->get_data().set_HO(data[1]);
  current_sv->get_data().set_TEN(data[2]);
  current_sv->get_data().set_PHAI(strcmp(data[3],"NAM")==0?0:1);
  current_sv->get_data().set_SDT(data[4]);
}

void search_sv(char ** data) {
  Node<LopCQ> * curr_lopcq = dslcq.head();

  while (curr_lopcq != NULL) {
    Node<SinhVien> * temp_sv = curr_lopcq->get_data().DSSV->head();
    while(temp_sv != NULL) {
      if (strcmp(temp_sv->get_data().get_MASV(), data[0]) == 0) {
        current_sv->set_data(temp_sv->get_data());
        return;
      }
      temp_sv = temp_sv->get_next();
    } 
    curr_lopcq = curr_lopcq->get_next();
  }
}

// int vitri_sv(DanhSachSinhVien* DSSV,char* MASV){
  // Node<SinhVien>* SV  = DSSV->head();
  // int counter = 0;
  // while(SV!=NULL){
    // if(strcmp(SV->get_data().get_MASV(),MASV)==0)
      // return counter;
    // counter++;
    // SV = SV->get_next();
  // }
  // return -1;
// }

// void delete_sv(char * ma_lop, char * ma_sv) {
  // DanhSachSinhVien * dssv = dslcq.get_dssv(ma_lop);

  // if (dssv == NULL) {
    // std::cout << "Lop khong ton tai\n";
    // return;
  // }
  // dssv->remove(vitri_sv(dssv,MASV));
// }

// void hieu_chinh_sv(char * ma_lopCQ, char* MASV, char** data) {
  // DanhSachSinhVien * dssv = dslcq.get_dssv(ma_lopCQ);

  // if (dssv == NULL) {
    // std::cout << "Lop khong ton tai\n";
    // return;
  // }

  // Node<SinhVien>* SV = dssv->p_head_;
  // bool flag=false;
  // while(SV != NULL){
    // if(strcmp(SV->get_data().get_MASV(),MASV)==0){
      // flag=true;
      // break;
    // }
    // SV=SV->get_next();
  // }
  // SinhVien sv(data[0],data[1],data[2],data[3]=="nam"?0:1,data[4],data[5]);
  // SV->set_data(sv);

// }


