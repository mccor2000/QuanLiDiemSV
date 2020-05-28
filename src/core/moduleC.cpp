#include "library.h"

void them_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, char** data) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);
  
  if (dssv == NULL) {
    std::cout << "Lop khong ton tai\n";
    return;
  }
  //tao sinh vien
  SinhVien sv(data[0],data[1],data[2],data[3]=="nam"?0:1,data[4],ma_lop);
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

void hieu_chinh_sv(DanhSachLopCQ &DSLCQ, char * ma_lop, char* MASV) {
  DanhSachSinhVien * dssv = DSLCQ.get_dssv(ma_lop);

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
  if(flag){
    SinhVien sv_data = SV->get_data();
    int choice;
    bool stop = false;
    while(!stop){
      std::cout <<  "Chon thuoc tinh ban muon chinh sua (Nhap 0 de dung):";
      std::cin >> choice;
      switch (choice){
          //dung vong lap
        case 0: {
          stop = true;
          break;
        }
          // Sua MASV
        case 1: {
          char str[15];
          cin.ignore();
          cin.getline(str,15);
          sv_data.set_MASV(str);
          break;
        }
          // Sua Ho
        case 2: {
          char str[16];
          cin.ignore();
          cin.getline(str,16);
          sv_data.set_HO(str);
          break;
        }
          // Sua Ten
        case 3: {
          char str[16];
          cin.ignore();
          cin.getline(str,16);
          sv_data.set_TEN(str);
          break;
        }
          //Sua SDT
        case 4: {
          char str[16];
          cin.ignore();
          cin.getline(str,16);
          sv_data.set_SDT(str);
          break;
        }
          // Sua Gioi tinh
        case 5: {
          bool sex;
          std::cin >> sex;
          sv_data.set_PHAI(sex);
          break;
        }
        //--
        default: {
          std::cout << "Nhap sai, moi ban nhap lai";
          break;
        }
      }
    }
    SV->set_data(sv_data);
  }
  else{
    std::cout << "khong tim thay sinh vien co MASV = " << MASV<<"\n";
  }
}


