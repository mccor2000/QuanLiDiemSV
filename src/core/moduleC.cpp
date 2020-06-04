#include "library.h"

void add_sv(char ** data) {
  DanhSachSinhVien * dssv = dslcq.get_dssv(data[5]);
  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  //tao sinh vien
  SinhVien sv(
      data[0],
      data[1],
      data[2],
      data[3] == "nam" ? 0 : 1, 
      data[4],
      data[5]
  );
  dssv->push_back(sv);
}
void update_sv(char **data_old,char **data_new){
  LopCQ lop = dslcq.get_lcq(data_old[5]);
  SinhVien* sv = lop.DSSV->search_sv(data_old[0]);
  sv->set_MASV(data_new[0]);
  sv->set_HO(data_new[1]);
  sv->set_TEN(data_new[2]);
  sv->set_PHAI((data_new[3]=="nam")?0:1);
  sv->set_SDT(data_new[4]);
  sv->set_MALOP(data_new[5]);
}

void change_MALOP(char* old, char* update){
  LopCQ result = dslcq.get_lcq(old);
  result.MALOP = update;
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


