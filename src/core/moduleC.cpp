#include "library.h"

void them_sv(DanhSachLopCQ &DSLCQ, char** data) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(data[5]);
  
  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  //tao sinh vien
  SinhVien sv(data[0],data[1],data[2],data[3]=="nam"?0:1,data[4],data[5]);
  dssv->push_back(sv);
}

int vitri_sv(DanhSachSinhVien* DSSV,char* MASV){
  Node<SinhVien>* SV  = DSSV->head();
  int counter = 0;
  while(SV!=NULL){
    if(strcmp(SV->get_data().get_MASV(),MASV)==0)
      return counter;
    counter++;
    SV = SV->get_next();
  }
  return -1;
}

void xoa_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, char* MASV) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);

  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  dssv->remove(vitri_sv(dssv,MASV));
}

void hieu_chinh_sv(DanhSachLopCQ &DSLCQ, char * ma_lopCQ, char* MASV, char** data) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lopCQ);

  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  
  Node<SinhVien>* SV = dssv->p_head_;
  bool flag=false;
  while(SV != NULL){
    if(strcmp(SV->get_data().get_MASV(),MASV)==0){
      flag=true;
      break;
    }
    SV=SV->get_next();
  }
  SinhVien sv(data[0],data[1],data[2],data[3]=="nam"?0:1,data[4],data[5]);
  SV->set_data(sv);
  
}


